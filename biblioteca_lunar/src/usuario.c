#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

void criarUsuarios(const char *nomeArquivo, Usuario usuario) {
    FILE *file = fopen(nomeArquivo, "a");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    fprintf(file, "%d;%s;%s;%s;%s;%d;%d;%.2f\n",
            usuario.idUsuario, usuario.nomeUsuario, usuario.senhaUsuario,
            usuario.nomeCompleto, usuario.cpfUsuario, usuario.reservaUsuario,
            usuario.pontosUsuario, usuario.multaUsuario);
    fclose(file);
}

void lerUsuarios(const char *nomeArquivo, Usuario *usuarios, int *quantidade) {
    FILE *file = fopen(nomeArquivo, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    *quantidade = 0; // Inicializa a quantidade de usuários
    while (fscanf(file, "%d;%49[^;];%19[^;];%99[^;];%14[^;];%d;%d;%f\n",
           &usuarios[*quantidade].idUsuario, usuarios[*quantidade].nomeUsuario,
           usuarios[*quantidade].senhaUsuario, usuarios[*quantidade].nomeCompleto,
           usuarios[*quantidade].cpfUsuario, &usuarios[*quantidade].reservaUsuario,
           &usuarios[*quantidade].pontosUsuario, &usuarios[*quantidade].multaUsuario) != EOF) {
        (*quantidade)++;
    }

    fclose(file);
}

void excluirUsuario(const char *nomeArquivo, int idUsuario) {
    FILE *file = fopen(nomeArquivo, "r");
    FILE *tempFile = fopen("data/temp.txt", "w");
    if (file == NULL || tempFile == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    char linha[256];
    int encontrado = 0;
    Usuario usuario;

    while (fgets(linha, sizeof(linha), file)) {
        sscanf(linha, "%d;%49[^;];%19[^;];%99[^;];%14[^;];%d;%d;%f",
               &usuario.idUsuario, usuario.nomeUsuario, usuario.senhaUsuario,
               usuario.nomeCompleto, usuario.cpfUsuario,
               &usuario.reservaUsuario, &usuario.pontosUsuario, &usuario.multaUsuario);
        if (usuario.idUsuario != idUsuario) {
            // Se o ID do usuário for diferente do que estamos excluindo, escrevemos no arquivo temporário
            fprintf(tempFile, "%d;%s;%s;%s;%s;%d;%d;%.2f\n",
                    usuario.idUsuario, usuario.nomeUsuario, usuario.senhaUsuario,
                    usuario.nomeCompleto, usuario.cpfUsuario, usuario.reservaUsuario,
                    usuario.pontosUsuario, usuario.multaUsuario);
        } else {
            encontrado = 1; // Usuário encontrado e não será copiado para o arquivo temporário
        }
    }

    fclose(file);
    fclose(tempFile);

    if (encontrado) {
        remove(nomeArquivo);  // Remove o arquivo original
        rename("data/temp.txt", nomeArquivo);  // Renomeia o arquivo temporário para o nome original
    } else {
        remove("data/temp.txt");  // Remove o arquivo temporário se o usuário não foi encontrado
    }
}

int obterIdDisponivel(const char *nomeArquivo) {
    FILE *file = fopen(nomeArquivo, "r");
    if (file == NULL) {
        return 1; // Se o arquivo não existe, comece com 1
    }

    int id;
    int ids[MAX_USUARIOS]; // Array para armazenar IDs de usuários
    int quantidade = 0;

    while (fscanf(file, "%d;%*[^;];%*[^;];%*[^;];%*[^;];%*d;%*d;%*f\n", &id) != EOF) {
        ids[quantidade++] = id;
    }
    fclose(file);

    // Encontra o ID disponível mais baixo
    for (int i = 1; i <= quantidade + 1; i++) {
        int encontrado = 0;
        for (int j = 0; j < quantidade; j++) {
            if (ids[j] == i) {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            return i; // Retorna o ID disponível
        }
    }

    return quantidade + 1; // Se não houver buracos, retorna o próximo
}