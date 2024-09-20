#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include "livro.h"

void criarLivros(const char *nomeArquivo, Livro livro) {
    FILE *file = fopen(nomeArquivo, "a"); // Abre o arquivo em modo de anexação
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    fprintf(file, "%d;%s;%s;%d;%d\n", livro.numeroLivro, livro.tituloLivro, livro.autorLivro, livro.anoLivro, livro.reservaLivro);
    fclose(file);
}

void lerLivros(const char *nomeArquivo, Livro *livros, int *quantidade) {
    FILE *file = fopen(nomeArquivo, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    *quantidade = 0; // Inicializa a quantidade de livros
    while (fscanf(file, "%d;%99[^;];%99[^;];%d;%d\n", &livros[*quantidade].numeroLivro, livros[*quantidade].tituloLivro,
           livros[*quantidade].autorLivro, &livros[*quantidade].anoLivro, &livros[*quantidade].reservaLivro) != EOF) {
        (*quantidade)++;
    }

    fclose(file);
}

void excluirLivro(const char *nomeArquivo, int numeroLivro) {
    FILE *file = fopen(nomeArquivo, "r");
    FILE *tempFile = fopen("data/temp.txt", "w");
    if (file == NULL || tempFile == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    char linha[256];
    int encontrado = 0;
    int numLivro;
    char titulo[100], autor[100];
    int ano, reserva;

    while (fgets(linha, sizeof(linha), file)) {
        sscanf(linha, "%d;%99[^;];%99[^;];%d;%d", &numLivro, titulo, autor, &ano, &reserva);
        if (numLivro != numeroLivro) {
            // Se o número do livro for diferente do que estamos excluindo, escrevemos no arquivo temporário
            fprintf(tempFile, "%d;%s;%s;%d;%d\n", numLivro, titulo, autor, ano, reserva);
        } else {
            encontrado = 1; // Livro encontrado e não será copiado para o arquivo temporário
        }
    }

    fclose(file);
    fclose(tempFile);

    if (encontrado) {
        remove(nomeArquivo);  // Remove o arquivo original
        rename("data/temp.txt", nomeArquivo);  // Renomeia o arquivo temporário para o nome original
    } else {
        remove("data/temp.txt");  // Remove o arquivo temporário se o livro não foi encontrado
    }
}

int obterNumeroDisponivel(const char *nomeArquivo) {
    FILE *file = fopen(nomeArquivo, "r");
    if (file == NULL) {
        return 1; // Se o arquivo não existe, comece com 1
    }

    int numero;
    int numeros[100]; // Array para armazenar números de livros
    int quantidade = 0;

    while (fscanf(file, "%d;%*[^;];%*[^;];%*d;%*d\n", &numero) != EOF) {
        numeros[quantidade++] = numero;
    }
    fclose(file);

    // Encontra o número disponível mais baixo
    for (int i = 1; i <= quantidade + 1; i++) {
        int encontrado = 0;
        for (int j = 0; j < quantidade; j++) {
            if (numeros[j] == i) {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            return i; // Retorna o número disponível
        }
    }

    return quantidade + 1; // Se não houver buracos, retorna o próximo
}

void reservarLivro(Livro *livro) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Salva a data da reserva no formato dd/mm/yyyy
    snprintf(livro->dataReserva, sizeof(livro->dataReserva), "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    // Define um prazo com base na quantidade de páginas (exemplo: 1 dia para cada 100 páginas)
    int diasDePrazo = (livro->paginas / 100) + 7;  // Cada 100 páginas dá 1 dia extra, mínimo de 7 dias
    livro->diasParaLiberar = diasDePrazo;
    
    livro->reservaLivro = 1;
    livro->multa = 0.0f;  // Inicialmente, a multa é zero
}

float calcularMulta(Livro *livro) {
    if (livro->reservaLivro == 0) {
        return 0.0f;  // Nenhuma multa se o livro não estiver reservado
    }

    // Data atual
    time_t t = time(NULL);
    struct tm tmAtual = *localtime(&t);

    // Converte a data da reserva para uma estrutura tm
    struct tm tmReserva;
    sscanf(livro->dataReserva, "%d/%d/%d", &tmReserva.tm_mday, &tmReserva.tm_mon, &tmReserva.tm_year);
    tmReserva.tm_mon -= 1;  // Ajuste do mês para a estrutura tm

    // Calcula a diferença entre as datas em segundos
    time_t tempoReserva = mktime(&tmReserva);
    time_t tempoAtual = mktime(&tmAtual);
    int diasAtraso = (difftime(tempoAtual, tempoReserva) / (60 * 60 * 24)) - livro->diasParaLiberar;

    if (diasAtraso > 0) {
        // Calcula a multa: R$2.00 por dia de atraso
        livro->multa = diasAtraso * 2.0f;
    } else {
        livro->multa = 0.0f;
    }

    return livro->multa;
}

void liberarLivro(Livro *livro) {
    if (livro->reservaLivro == 1) {
        float multa = calcularMulta(livro);
        if (multa > 0) {
            printf("Atenção! Você está com uma multa de R$%.2f por atraso.\n", multa);
        }

        // Libera o livro
        livro->reservaLivro = 0;
        strcpy(livro->dataReserva, "");  // Limpa a data de reserva
        livro->diasParaLiberar = 0;
        livro->multa = 0.0f;

        printf("Livro devolvido com sucesso!\n");
    } else {
        printf("Este livro não está reservado.\n");
    }
}

void exibirDetalhesLivro(Livro *livro) {
    printf("Livro: %s\n", livro->tituloLivro);
    printf("Autor: %s\n", livro->autorLivro);
    printf("Ano: %d\n", livro->anoLivro);
    printf("Páginas: %d\n", livro->paginas);

    if (livro->reservaLivro == 1) {
        printf("Status: Reservado\n");
        printf("Data de reserva: %s\n", livro->dataReserva);
        printf("Dias restantes para liberar: %d\n", livro->diasParaLiberar);
        if (calcularMulta(livro) > 0) {
            printf("Multa acumulada: R$%.2f\n", livro->multa);
        } else {
            printf("Nenhuma multa acumulada.\n");
        }
    } else {
        printf("Status: Disponível\n");
    }
}
