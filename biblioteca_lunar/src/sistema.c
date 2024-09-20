#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>  
#include "sistema.h"
#include "usuario.h"
#include "livro.h"

const char* ADMIN_USERNAME = "admin";
const char* ADMIN_PASSWORD = "admin123";
const char* USUARIO_USERNAME = "user";
const char* USUARIO_PASSWORD = "user123";

// Variáveis globais de controle de tela
int telaPrincipalRoda = 1;
int telaInicialRoda = 1;
int telaAdministrativaRoda = 1;
int telaConfirmarAutenticacaoAdministradorRoda = 1;
int telaCodigoCadastroRoda = 1;
int telaErroLoginRoda = 1;
int codigoCadastro = -1;

void telaPrincipal() {
    // Obtém a data e hora atuais
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    limparTela();
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| BIBLIOTECA LUNAR - \"TELA PRINCIPAL\"                     DATA: %02d/%02d/%04d  |\n", 
           tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| 1. Login de usuário.                                                      |\n");
    printf("|                                                                           |\n");
    printf("| 2. Criar cadastro.                                                        |\n");
    printf("|                                                                           |\n");
    printf("| 3. Área administrativa.                                                   |\n");
    printf("|                                                                           |\n");
    printf("| 4. Sair.                                                                  |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n\n");
    printf("[Mensagem:] Digite a opção desejada: ");

    int opcaoTelaPrincipal;

    // Loop para garantir que a entrada seja válida
    while (scanf("%d", &opcaoTelaPrincipal) != 1) {
        while (getchar() != '\n');  // Limpa o buffer de entrada

        // Exibe o menu novamente em caso de erro
        limparTela();
        printf("\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("| BIBLIOTECA LUNAR - \"TELA PRINCIPAL\"                     DATA: %02d/%02d/%04d  |\n", 
               tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("| 1. Login de usuário.                                                      |\n");
        printf("|                                                                           |\n");
        printf("| 2. Criar cadastro.                                                        |\n");
        printf("|                                                                           |\n");
        printf("| 3. Área administrativa.                                                   |\n");
        printf("|                                                                           |\n");
        printf("| 4. Sair.                                                                  |\n");
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n\n");
        printf("[Mensagem:] Digite uma das opções (1, 2, 3 ou 4) para continuar: ");
    }

    // Processa a opção escolhida pelo usuário
    switch (opcaoTelaPrincipal) {
        case 1:
            // Chama a função de login de usuário
            limparTela();
            telaLoginUsuario();
            break;
        case 2:
            limparTela();
            telaValidaCodigoUsuario();  // Chama a função de validação do código de cadastro
            break;
        case 3:
            limparTela();
            telaConfirmarAutenticacaoAdministrador();
            break;
        case 4:
            limparTela();
            printf("\n");
            printf("+---------------------------------------------------------------------------+\n");
            printf("|                                                                           |\n");
            printf("| BIBLIOTECA LUNAR - \"ENCERRANDO O PROGRAMA\"              DATA: %02d/%02d/%04d  |\n", 
                   tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
            printf("|                                                                           |\n");
            printf("+---------------------------------------------------------------------------+\n\n");
            printf("[Mensagem:] Você escolheu sair do programa. Até mais!\n\n\n\n\n\n\n");
            telaPrincipalRoda = 0;  // Sinaliza que a tela principal não está mais rodando
            return;
        default:
            limparTela();
            telaPrincipal();  // Chama novamente a função caso a opção seja inválida
            break;
    }
}

void telaInicial() {
    // Obtém a data e hora atuais
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| BIBLIOTECA LUNAR - \"TELA INICIAL\"                       DATA: %02d/%02d/%04d  |\n", 
           tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| Instituição.......: SENAC - Serviço Nacional de Aprendizagem Comercial    |\n");
    printf("|                                                                           |\n");
    printf("| Desenvolvedores...: Alice, Natan e Samuel                                 |\n");
    printf("|                                                                           |\n");
    printf("| Código do Job.....: C - Linguagem de Programação                          |\n");
    printf("|                                                                           |\n");
    printf("| Curso.............: Tec. Análise e Desenvolvimento de Sistemas            |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n\n");
    printf("[Mensagem:] Digite \"1\" para iniciar ou \"2\" para sair do programa: ");

    int opcaoTelaInicial;

    // Loop para garantir que a entrada seja válida
    while (scanf("%d", &opcaoTelaInicial) != 1) {
        while (getchar() != '\n');  // Limpa o buffer de entrada

        // Exibe o menu novamente em caso de erro
        printf("\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("| BIBLIOTECA LUNAR - \"TELA INICIAL\"                       DATA: %02d/%02d/%04d  |\n", 
               tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("| Instituição.......: SENAC - Serviço Nacional de Aprendizagem Comercial    |\n");
        printf("|                                                                           |\n");
        printf("| Desenvolvedores...: Alice, Natan e Samuel                                 |\n");
        printf("|                                                                           |\n");
        printf("| Código do Job.....: C - Linguagem de Programação                          |\n");
        printf("|                                                                           |\n");
        printf("| Curso.............: Tec. Análise e Desenvolvimento de Sistemas            |\n");
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n\n");
        printf("[Mensagem:] Digite \"1\" para iniciar ou \"2\" para sair do programa: ");
    }

    // Processa a opção escolhida pelo usuário
    switch (opcaoTelaInicial) {
        case 1:
            limparTela();
            telaPrincipal();
            break;
        case 2:
            printf("\n");
            printf("+---------------------------------------------------------------------------+\n");
            printf("|                                                                           |\n");
            printf("| BIBLIOTECA LUNAR - \"ENCERRANDO O PROGRAMA\"              DATA: %02d/%02d/%04d  |\n", 
                   tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
            printf("|                                                                           |\n");
            printf("+---------------------------------------------------------------------------+\n\n");
            printf("[Mensagem:] Você escolheu sair do programa. Até mais!\n\n\n\n\n\n\n");
            telaInicialRoda = 0;  // Sinaliza que a tela inicial não está mais rodando
            break;
        default:
            limparTela();
            telaInicial();  // Chama novamente a função caso a opção seja inválida
            break;
    }
}

void telaAdministrativa() {
    // Obtém a data e hora atuais
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    limparTela();
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| BIBLIOTECA LUNAR - \"MENU ADMINISTRATIVO\"                DATA: %02d/%02d/%04d  |\n", 
           tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| 1. Manutenção de usuários.                                                |\n");
    printf("|                                                                           |\n");
    printf("| 2. Manutenção de livros.                                                  |\n");
    printf("|                                                                           |\n");
    printf("| 3. Gerar código de cadastro.                                              |\n");
    printf("|                                                                           |\n");
    printf("| 4. Voltar à tela principal.                                               |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n\n");
    printf("[Mensagem:] Digite a opção desejada: ");

    int opcaoTelaAdministrativa;

    // Loop para garantir que a entrada seja válida
    while (scanf("%d", &opcaoTelaAdministrativa) != 1) {
        while (getchar() != '\n');  // Limpa o buffer de entrada

        // Exibe o menu novamente em caso de erro
        limparTela();
        printf("\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("| BIBLIOTECA LUNAR - \"MENU ADMINISTRATIVO\"                DATA: %02d/%02d/%04d  |\n", 
               tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("| 1. Manutenção de usuários.                                                |\n");
        printf("|                                                                           |\n");
        printf("| 2. Manutenção de livros.                                                  |\n");
        printf("|                                                                           |\n");
        printf("| 3. Gerar código de cadastro.                                              |\n");
        printf("|                                                                           |\n");
        printf("| 4. Voltar à tela principal.                                               |\n");
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n\n");
        printf("[Mensagem:] Digite uma das opções (1, 2, 3 ou 4) para continuar: ");
    }

    // Processa a opção escolhida pelo usuário
    switch (opcaoTelaAdministrativa) {
        case 1:
            // Abre a tela de gerenciador de usuários
            limparTela();
            telaGerenciadorDeUsuarios();
            break;
        case 2:
            // Abre a tela de gerenciador de livros
            limparTela();
            telaGerenciadorDeLivros();
            break;
        case 3:
            // Gera o código de cadastro
            limparTela();
            gerarCodigoCadastro();
            telaCodigoCadastroRoda = 1;
            limparTela();
            telaCodigoCadastro();
            break;
        case 4:
            // Retorna à tela principal
            limparTela();
            telaPrincipal();
            return;
        default:
            // Exibe o menu administrativo novamente em caso de opção inválida
            limparTela();
            telaAdministrativa();
            break;
    }
}

void telaCodigoCadastro() {
    // Obtém a data e hora atuais
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    // Loop de controle da tela
    while (telaCodigoCadastroRoda == 1) {
        printf("\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("| BIBLIOTECA LUNAR - \"CÓDIGO DE CADASTRO\"                 DATA: %02d/%02d/%04d  |\n", 
               tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("| [Mensagem:] Atenção, este código só pode ser usado uma vez. Finalize      |\n");
        printf("|             o primeiro cadastro ou gere um novo código.                   |\n");
        printf("|                                                                           |\n");
        printf("|             Caso um novo código seja gerado, o anterior será invalidado.  |\n");
        printf("|                                                                           |\n");
        printf("|                                                                           |\n");
        printf("|             Seu código é %i.                                            |\n", codigoCadastro);
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n\n");
        printf("[Mensagem:] Essa tela ficará ativa por 20 segundos... ");
        fflush(stdout);

        sleep(20);  // Espera por 20 segundos

        printf("\n\n");
        telaCodigoCadastroRoda = 0;  // Fecha a tela de código de cadastro
        limparTela();
        telaAdministrativa();        // Retorna ao menu administrativo
    }
}

void telaGerenciadorDeUsuarios() {
    // Obtém a data e hora atuais
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    limparTela();
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| BIBLIOTECA LUNAR - \"GERENCIADOR DE USUÁRIOS\"            DATA: %02d/%02d/%04d  |\n", 
           tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| 1. Consultar usuários.                                                    |\n");
    printf("|                                                                           |\n");
    printf("| 2. Editar/excluir usuário.                                                |\n");
    printf("|                                                                           |\n");
    printf("| 3. Liberar multas.                                                        |\n");
    printf("|                                                                           |\n");
    printf("| 4. Voltar ao menu administrativo.                                         |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n\n");
    printf("[Mensagem:] Digite a opção desejada: ");

    int opcaoGerenciadorUsuarios;

    // Valida a opção de entrada
    while (scanf("%d", &opcaoGerenciadorUsuarios) != 1) {
        while (getchar() != '\n');  // Limpa o buffer de entrada
        limparTela();
        printf("\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("| BIBLIOTECA LUNAR - \"GERENCIADOR DE USUÁRIOS\"            DATA: %02d/%02d/%04d  |\n", 
               tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("| 1. Consultar usuários.                                                    |\n");
        printf("|                                                                           |\n");
        printf("| 2. Editar/excluir usuário.                                                |\n");
        printf("|                                                                           |\n");
        printf("| 3. Liberar multas.                                                        |\n");
        printf("|                                                                           |\n");
        printf("| 4. Voltar ao menu administrativo.                                         |\n");
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n\n");
        printf("[Mensagem:] Digite uma das opções válidas: ");
    }

    // Processa a escolha do usuário
    switch (opcaoGerenciadorUsuarios) {
        case 1: {
    // Consulta e exibe todos os usuários
    Usuario usuarios[100];
    int quantidade;
    lerUsuarios("data/usuarios.txt", usuarios, &quantidade);  // Lê todos os usuários

    limparTela();
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| BIBLIOTECA LUNAR - \"USUÁRIOS CADASTRADOS NO SISTEMA\"    DATA: %02d/%02d/%04d  |\n", 
           tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    
    // Loop para exibir todos os usuários cadastrados
    for (int i = 0; i < quantidade; i++) {
        printf("|                                                                            \n");
        printf("| Id = %d\n", usuarios[i].idUsuario);  // Use o campo correto aqui
        printf("|                                                                            \n");
        printf("| Usuário......: %s\n", usuarios[i].nomeUsuario);
        printf("| Nome Completo: %s\n", usuarios[i].nomeCompleto);
        printf("| CPF..........: %s\n", usuarios[i].cpfUsuario);  // Ajuste conforme o tipo
        printf("|                                                                            \n");
        printf("| Reservas.....: %d\n", usuarios[i].reservaUsuario);  // Ajuste conforme o tipo
        printf("| Nível........: %d\n", usuarios[i].pontosUsuario);
        printf("| Multa........: %.2f\n", usuarios[i].multaUsuario);  // Ajuste conforme o tipo
        printf("|                                                                            \n");
        printf("+---------------------------------------------------------------------------+\n");
    }

    printf("\n[Mensagem:] Pressione ENTER para voltar ao menu.");
    getchar(); // Aguarda o usuário pressionar Enter
    getchar(); // Captura o Enter após a leitura da opção
    limparTela();
    telaGerenciadorDeUsuarios();
    break;
}
        case 2: {
            // Chama a função para editar ou excluir um livro
            limparTela();
            telaUsuarioEditarExcluir();
            break;
        }
        case 3:
            // Liberar multas (implemente a funcionalidade)
            printf("\n[Mensagem:] Você escolheu liberar multas.\n");
            // Chame uma função para liberar reservas aqui, se disponível
            break;
        case 4:
            // Voltar ao menu administrativo
            limparTela();
            telaAdministrativa();
            break;
        default:
            // Caso a opção seja inválida, exibe a tela novamente
            limparTela();
            telaGerenciadorDeUsuarios();
            break;
    }
}

void telaGerenciadorDeLivros() {
    // Obtém a data e hora atuais
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    limparTela();
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| BIBLIOTECA LUNAR - \"GERENCIADOR DE LIVROS\"              DATA: %02d/%02d/%04d  |\n", 
           tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| 1. Consultar livros.                                                      |\n");
    printf("|                                                                           |\n");
    printf("| 2. Editar/excluir livros.                                                 |\n");
    printf("|                                                                           |\n");
    printf("| 3. Criar livros.                                                          |\n");
    printf("|                                                                           |\n");
    printf("| 4. Voltar ao menu administrativo.                                         |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n\n");
    printf("[Mensagem:] Digite a opção desejada: ");

    int opcaoGerenciadorLivros;

    // Valida a opção de entrada
    while (scanf("%d", &opcaoGerenciadorLivros) != 1) {
        while (getchar() != '\n');  // Limpa o buffer de entrada
        limparTela();
        printf("\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("| BIBLIOTECA LUNAR - \"GERENCIADOR DE LIVROS\"              DATA: %02d/%02d/%04d  |\n", 
               tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("| 1. Consultar livros.                                                      |\n");
        printf("|                                                                           |\n");
        printf("| 2. Editar/excluir livros.                                                 |\n");
        printf("|                                                                           |\n");
        printf("| 3. Criar livros.                                                          |\n");
        printf("|                                                                           |\n");
        printf("| 4. Voltar ao menu administrativo.                                         |\n");
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n\n");
        printf("[Mensagem:] Digite uma das 4 opções para continuar: ");
    }

    switch (opcaoGerenciadorLivros) {
        case 1: {
            // Consulta e exibe todos os livros
            Livro livros[100];
            int quantidade;
            lerLivros("data/livros.txt", livros, &quantidade);
            limparTela();
            printf("\n");
            printf("+---------------------------------------------------------------------------+\n");
            printf("|                                                                           |\n");
            printf("| BIBLIOTECA LUNAR - \"LIVROS CADASTRADOS NO SISTEMA\"      DATA: %02d/%02d/%04d  |\n", 
                   tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
            printf("|                                                                           |\n");
            printf("+---------------------------------------------------------------------------+\n");
            
            // Loop para exibir todos os livros cadastrados
            for (int i = 0; i < quantidade; i++) {
                printf("|                                                                            \n");
                printf("| Id = %d\n", livros[i].numeroLivro);
                printf("|                                                                            \n");
                printf("| Título........: %s\n", livros[i].tituloLivro);
                printf("| Autor.........: %s\n", livros[i].autorLivro);
                printf("| Ano...........: %d\n", livros[i].anoLivro);
                printf("|                                                                            \n");
                printf("| Reservado.....: %s\n", livros[i].reservaLivro ? "Sim" : "Não");
                printf("| Usuário.......:   \n");
                printf("| Dias restantes:   \n");
                printf("|                                                                            \n");
                printf("+---------------------------------------------------------------------------+\n");
            }

            printf("\n[Mensagem:] Pressione ENTER para voltar ao menu.");
            getchar(); // Aguarda o usuário pressionar Enter
            getchar(); // Captura o Enter após a leitura da opção
            limparTela();
            telaGerenciadorDeLivros();
            break;
        }
        case 2: {
            // Chama a função para editar ou excluir um livro
            limparTela();
            telaLivroEditarExcluir();
            break;
        }
        case 3: {
            // Cria um novo livro
            Livro novoLivro;
            novoLivro.numeroLivro = obterNumeroDisponivel("data/livros.txt");
            limparTela();
            printf("\n");
            printf("+---------------------------------------------------------------------------+\n");
            printf("|                                                                           |\n");
            printf("| BIBLIOTECA LUNAR - \"CRIAÇÃO DE LIVROS\"                  DATA: %02d/%02d/%04d  |\n", 
                   tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
            printf("|                                                                           |\n");
            printf("+---------------------------------------------------------------------------+\n");
            printf("|                                                                           |\n");
            printf("| [Mensagem:] Você está na tela de criação de livros!                       |\n");
            printf("|                                                                           |\n");
            printf("|             Primeiro, digite o título... Aguardando digitação...          |\n");
            printf("|                                                                           |\n");
            printf("|                                                                           |\n");
            printf("|                                                                           |\n");
            printf("|                                                                           |\n");
            printf("|                                                                           |\n");
            printf("+---------------------------------------------------------------------------+\n\n");
            printf("[Mensagem:] Digite o título: ");
            scanf(" %[^\n]", novoLivro.tituloLivro);
            
            limparTela();
            printf("\n");
            printf("+---------------------------------------------------------------------------+\n");
            printf("|                                                                           |\n");
            printf("| BIBLIOTECA LUNAR - \"CRIAÇÃO DE LIVROS\"                  DATA: %02d/%02d/%04d  |\n", 
                   tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
            printf("|                                                                           |\n");
            printf("+---------------------------------------------------------------------------+\n");
            printf("|                                                                           |\n");
            printf("| [Mensagem:] Você está na tela de criação de livros!                       |\n");
            printf("|                                                                           |\n");
            printf("|             Primeiro, digite o título..........Ok!                        |\n");
            printf("|                                                                           |\n");
            printf("|             Segundo, digite o nome do autor... Aguardando digitação...    |\n");
            printf("|                                                                           |\n");
            printf("|                                                                           |\n");
            printf("|                                                                           |\n");
            printf("+---------------------------------------------------------------------------+\n\n");
            printf("[Mensagem:] Digite o autor: ");
            scanf(" %[^\n]", novoLivro.autorLivro);
            
            limparTela();
            printf("\n");
            printf("+---------------------------------------------------------------------------+\n");
            printf("|                                                                           |\n");
            printf("| BIBLIOTECA LUNAR - \"CRIAÇÃO DE LIVROS\"                  DATA: %02d/%02d/%04d  |\n", 
                   tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
            printf("|                                                                           |\n");
            printf("+---------------------------------------------------------------------------+\n");
            printf("|                                                                           |\n");
            printf("| [Mensagem:] Você está na tela de criação de livros!                       |\n");
            printf("|                                                                           |\n");
            printf("|             Primeiro, digite o título..........Ok!                        |\n");
            printf("|                                                                           |\n");
            printf("|             Segundo, digite o nome do autor....Ok!                        |\n");
            printf("|                                                                           |\n");
            printf("|             Terceiro, digite o ano do livro... Aguardando digitação...    |\n");
            printf("|                                                                           |\n");
            printf("+---------------------------------------------------------------------------+\n\n");
            printf("[Mensagem:] Digite o ano: ");
            scanf("%d", &novoLivro.anoLivro);
            
            novoLivro.reservaLivro = 0;  // Inicialmente o livro não está reservado

            criarLivros("data/livros.txt", novoLivro);
            limparTela();
            printf("\n");
            printf("+---------------------------------------------------------------------------+\n");
            printf("|                                                                           |\n");
            printf("| BIBLIOTECA LUNAR - \"CRIAÇÃO DE LIVROS\"                  DATA: %02d/%02d/%04d  |\n", 
                   tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
            printf("|                                                                           |\n");
            printf("+---------------------------------------------------------------------------+\n");
            printf("|                                                                           |\n");
            printf("| [Mensagem:] Livro cadastrado com sucesso!                                 |\n");
            printf("|                                                                           |\n");
            printf("|                                                                           |\n");
            printf("|                                                                           |\n");
            printf("|                                                                           |\n");
            printf("|                                                                           |\n");
            printf("|                                                                           |\n");
            printf("|                                                                           |\n");
            printf("+---------------------------------------------------------------------------+\n\n");
            printf("[Mensagem:] Pressione ENTER para voltar ao menu.");
            getchar(); // Aguarda o usuário pressionar Enter
            getchar(); // Captura o Enter após a leitura da opção
            limparTela();
            telaGerenciadorDeLivros();
            break;
        }
        case 4:
            // Retorna ao menu administrativo
            limparTela();
            telaAdministrativa();
            break;
        default:
            limparTela();
            telaGerenciadorDeLivros();
            break;
    }
}

void telaConfirmarAutenticacaoAdministrador() {
    // Obtém a data e hora atuais
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    limparTela();
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| BIBLIOTECA LUNAR - \"AUTENTICAÇÃO DE ADMINISTRADOR\"      DATA: %02d/%02d/%04d  |\n", 
           tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| [Mensagem:] Para acessar o menu administrativo, é necessário fazer        |\n");
    printf("|             autenticação com o usuário de administrador do sistema.       |\n");
    printf("|                                                                           |\n");
    printf("|             Se as credenciais forem inválidas, você voltará para o        |\n");
    printf("|             menu principal.                                               |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n\n");
    
    // Entrada de login do administrador
    char usuarioAdmin[50], senhaAdmin[50];
    printf("[Mensagem:] Digite o login do administrador: ");
    scanf("%s", usuarioAdmin);
    
    limparTela();
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| BIBLIOTECA LUNAR - \"AUTENTICAÇÃO DE ADMINISTRADOR\"      DATA: %02d/%02d/%04d  |\n", 
           tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| [Mensagem:] Para acessar o menu administrativo, é necessário fazer        |\n");
    printf("|             autenticação com o usuário de administrador do sistema.       |\n");
    printf("|                                                                           |\n");
    printf("|             Se as credenciais forem inválidas, você voltará para o        |\n");
    printf("|             menu principal.                                               |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n\n");
    printf("[Mensagem:] Digite o senha do administrador: ");
    scanf("%s", senhaAdmin);

    // Valida as credenciais do administrador
    if (validarUsuarioAdministrador(usuarioAdmin, senhaAdmin)) {
        limparTela();
        telaAdministrativa();
    } else {
        telaErroLoginRoda = 1;  // Ativa a tela de erro
        limparTela();
        telaErroLogin();        // Chama a função de erro de login
    }
}

void telaConfirmarAutenticacaoUsuario() {
    // Obtém a data e hora atuais
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    limparTela();
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| BIBLIOTECA LUNAR - \"AUTENTICAÇÃO\"                       DATA: %02d/%02d/%04d  |\n", 
           tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| [Mensagem:] Seja bem-vindo de volta! Você está na tela de login da        |\n");
    printf("|             Biblioteca Lunar.                                             |\n");
    printf("|                                                                           |\n");
    printf("|             Siga conosco nessa jornada de aventura e imaginação!          |\n");
    printf("|             A Lunar deseja um lindo e agradável dia!                      |\n");
    printf("|                                                                           |\n");
    printf("|             Digite suas credenciais para prosseguir:                      |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n\n");
    
    // Entrada de login do usuário
    char usuarioUsuario[50], senhaUsuario[50];
    printf("[Mensagem:] Digite seu login de usuário: ");
    scanf(" %[^\n]", usuarioUsuario);
    
    // Exibe a tela novamente para solicitar a senha
    limparTela();
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| BIBLIOTECA LUNAR - \"AUTENTICAÇÃO\"                       DATA: %02d/%02d/%04d  |\n", 
           tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| [Mensagem:] Seja bem-vindo de volta! Você está na tela de login da        |\n");
    printf("|             Biblioteca Lunar.                                             |\n");
    printf("|                                                                           |\n");
    printf("|             Siga conosco nessa jornada de aventura e imaginação!          |\n");
    printf("|             A Lunar deseja um lindo e agradável dia!                      |\n");
    printf("|                                                                           |\n");
    printf("|             Digite suas credenciais para prosseguir:                      |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n\n");
    printf("[Mensagem:] Digite sua senha de usuário: ");
    scanf(" %s", senhaUsuario);

    // Valida as credenciais do usuário
    if (validarUsuarioUsuario(usuarioUsuario, senhaUsuario)) {
        // Sucesso no login, redireciona para a tela principal
        limparTela();
        telaPrincipal();
    } else {
        // Falha no login, chama a tela de erro de login
        telaErroLoginRoda = 1;  // Ativa a tela de erro
        limparTela();
        telaErroLogin();        // Chama a função de erro de login
    }
}

void telaErroLogin() {
    // Obtém a data e hora atuais
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    // Loop de controle da tela
    while (telaErroLoginRoda == 1) {
        limparTela();
        printf("\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("| BIBLIOTECA LUNAR - \"AUTENTICAÇÃO\"                       DATA: %02d/%02d/%04d  |\n", 
               tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("| [Mensagem:] Credenciais inválidas. Por segurança, você será redirecionado |\n");
        printf("|             para a tela principal.                                        |\n");
        printf("|                                                                           |\n");
        printf("|                                                                           |\n");
        printf("|                                                                           |\n");
        printf("|                                                                           |\n");
        printf("|                                                                           |\n");
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n\n");
        printf("[Mensagem:] Aguarde 10 segundos... ");
        fflush(stdout);

        sleep(10);  // Espera por 10 segundos

        printf("\n");
        telaErroLoginRoda = 0;  // Fecha a tela de erro
        limparTela();
        telaPrincipal();        // Redireciona para a tela principal
    }
}

void gerarCodigoCadastro() {
    codigoCadastro = rand() % 9000 + 1000;  // Gera um código entre 1000 e 9999
}

void limparTela() {
    system("clear");
}

int validarUsuarioAdministrador(const char* usuarioAdmin, const char* senhaAdmin) {
    // Compara as credenciais fornecidas com as credenciais predefinidas
    return (strcmp(usuarioAdmin, ADMIN_USERNAME) == 0 && strcmp(senhaAdmin, ADMIN_PASSWORD) == 0);
}

// Função para validar o login do usuário
int validarUsuarioUsuario(const char* usuarioUsuario, const char* senhaUsuario) {
    // Compara as credenciais fornecidas com as credenciais predefinidas
    return (strcmp(usuarioUsuario, USUARIO_USERNAME) == 0 && strcmp(senhaUsuario, USUARIO_PASSWORD) == 0);
}
void telaLoginUsuario() {
    // Obtém a data e hora atuais
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    limparTela();
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| BIBLIOTECA LUNAR - \"AUTENTICAÇÃO\"                       DATA: %02d/%02d/%04d  |\n", 
           tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| [Mensagem:] É sua primeira vez aqui? Se sim, será necessário a criação    |\n");
    printf("|             do seu cadastro no sistema para autenticação.                 |\n");
    printf("|                                                                           |\n");
    printf("|             Se não, é só continuar para sua autenticação!                 |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n\n");
    printf("[Mensagem:] Já tem cadastro? Digite ""1"", não tem? Digite ""2"": ");

    int opcaoLoginUsuario;

    // Valida a opção de entrada
    while (scanf("%d", &opcaoLoginUsuario) != 1) {
        while (getchar() != '\n');  // Limpa o buffer de entrada
        limparTela();
        printf("\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("| BIBLIOTECA LUNAR - \"AUTENTICAÇÃO\"                       DATA: %02d/%02d/%04d  |\n", 
               tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("| [Mensagem:] É sua primeira vez aqui? Então será necessário a criação      |\n");
        printf("|             do seu cadastro no sistema para autenticação.                 |\n");
        printf("|                                                                           |\n");
        printf("|             Se já tiver um cadastro, digite \"1\" para continuar.           |\n");
        printf("|             Se não tiver um cadastro, digite \"2\" para retornar.           |\n");
        printf("|                                                                           |\n");
        printf("|                                                                           |\n");
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n\n");
        printf("[Mensagem:] Seleção inválida, escolha opção \"1\" ou \"2\": ");
    }

    // Processa a escolha do usuário
    switch (opcaoLoginUsuario) {
        case 1:
            // Chama a função de autenticação do usuário
            limparTela();
            telaConfirmarAutenticacaoUsuario();
            break;
        case 2:
            // Retorna à tela principal
            limparTela();
            telaPrincipal();
            break;
        default:
            // Caso a opção seja inválida, exibe a tela novamente
            limparTela();
            telaLoginUsuario();
            break;
    }
}
void telaValidaCodigoUsuario() {
    // Obtém a data e hora atuais
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    limparTela();
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| BIBLIOTECA LUNAR - \"CADASTRO DE USUÁRIO\"                DATA: %02d/%02d/%04d  |\n", 
           tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| [Mensagem:] É muito bom ter você conosco, mas para isso, você precisa     |\n");
    printf("|             da liberação do seu código de usuário.                        |\n");
    printf("|                                                                           |\n");
    printf("|             Como funciona: Peça ao administrador do sistema para estar    |\n");
    printf("|             gerando seu código de cadastro.                               |\n");
    printf("|                                                                           |\n");
    printf("|             Se já obteve um, digite-o para continuar o seu cadastro!      |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n\n");
    printf("[Mensagem:] Está com o código? \"1\" para Sim ou \"2\" para Não: ");

    int opcaoCodigo;
    
    // Valida a entrada da opção
    while (scanf("%d", &opcaoCodigo) != 1 || (opcaoCodigo != 1 && opcaoCodigo != 2)) {
        while (getchar() != '\n');  // Limpa o buffer de entrada
        limparTela();
        printf("\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("| BIBLIOTECA LUNAR - \"CADASTRO DE USUÁRIO\"                DATA: %02d/%02d/%04d  |\n", 
            tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("| [Mensagem:] É muito bom ter você conosco, mas para isso, você precisa     |\n");
        printf("|             da liberação do seu código de usuário.                        |\n");
        printf("|                                                                           |\n");
        printf("|             Como funciona: Peça ao administrador do sistema para estar    |\n");
        printf("|             gerando seu código de cadastro.                               |\n");
        printf("|                                                                           |\n");
        printf("|             Se já obteve um, digite-o para continuar o seu cadastro!      |\n");
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n\n");
        printf("[Mensagem:] Erro! Digite \"1\" para Sim ou \"2\" para Não: ");
    }

    if (opcaoCodigo == 1) {
        // Usuário possui o código de cadastro, validar o código
        int codigoEntrada;
        limparTela();
        printf("\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("| BIBLIOTECA LUNAR - \"CADASTRO DE USUÁRIO\"                DATA: %02d/%02d/%04d  |\n", 
            tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("| [Mensagem:] Esperando a confirmação do código de cadastro...              |\n");
        printf("|                                                                           |\n");
        printf("|                                                                           |\n");
        printf("|                                                                           |\n");
        printf("|                                                                           |\n");
        printf("|                                                                           |\n");
        printf("|                                                                           |\n");
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n\n");
        printf("\n[Mensagem:] Por favor, digite o código de cadastro: ");
        scanf(" %d", &codigoEntrada);

        // Verifica se o código digitado é igual ao código gerado
        if (codigoEntrada == codigoCadastro && codigoCadastro != -1) {
            limparTela();
            printf("\n");
            printf("+---------------------------------------------------------------------------+\n");
            printf("|                                                                           |\n");
            printf("| BIBLIOTECA LUNAR - \"CADASTRO DE USUÁRIO\"                DATA: %02d/%02d/%04d  |\n", 
                    tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
            printf("|                                                                           |\n");
            printf("+---------------------------------------------------------------------------+\n");
            printf("|                                                                           |\n");
            printf("| [Mensagem:] Código de cadastro validado com sucesso!                      |\n");
            printf("|                                                                           |\n");
            printf("|                                                                           |\n");
            printf("|                                                                           |\n");
            printf("|                                                                           |\n");
            printf("|                                                                           |\n");
            printf("|                                                                           |\n");
            printf("|                                                                           |\n");
            printf("+---------------------------------------------------------------------------+\n\n");
            printf("[Mensagem:] Você será redirecionado em 5 segundos...");
            fflush(stdout);

            sleep(5);  // Espera por 5 segundos

            // Invalida o código após o uso
            codigoCadastro = -1;

            // Chama a tela de cadastro de usuário
            printf("\n");
            limparTela();
            telaCadastroUsuario("data/usuarios.txt");

        } else {
            limparTela();
            printf("\n");
            printf("+---------------------------------------------------------------------------+\n");
            printf("|                                                                           |\n");
            printf("| BIBLIOTECA LUNAR - \"CADASTRO DE USUÁRIO\"                DATA: %02d/%02d/%04d  |\n", 
                    tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
            printf("|                                                                           |\n");
            printf("+---------------------------------------------------------------------------+\n");
            printf("|                                                                           |\n");
            printf("| [Mensagem:] O código inserido é inválido ou já foi utilizado.             |\n");
            printf("|                                                                           |\n");
            printf("|             Peça ao administrador para gerar um novo código.              |\n");
            printf("|                                                                           |\n");
            printf("|                                                                           |\n");
            printf("|                                                                           |\n");
            printf("|                                                                           |\n");
            printf("|                                                                           |\n");
            printf("+---------------------------------------------------------------------------+\n\n");
            printf("[Mensagem:] Aguarde 10 segundos... ");
            fflush(stdout);

            sleep(10);  // Espera por 10 segundos

            // Retorna à tela principal ou oferece a opção de tentar novamente
            limparTela();
            telaPrincipal();
        }

    } else if (opcaoCodigo == 2) {
        // Caso o usuário não tenha o código, retorna à tela principal
        limparTela();
        telaPrincipal();
    }
}
void telaUsuarioEditarExcluir() {
    // Obtém a data e hora atuais
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| BIBLIOTECA LUNAR - \"EDITAR/EXCLUIR USUÁRIOS\"            DATA: %02d/%02d/%04d  |\n", 
           tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| [Mensagem:] Escolha o que deseja fazer:                                   |\n");
    printf("|                                                                           |\n");
    printf("|             \"1\" para editar.                                              |\n");
    printf("|                                                                           |\n");
    printf("|             \"2\" para excluir.                                             |\n");
    printf("|                                                                           |\n");
    printf("|             \"3\" para voltar.                                              |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n\n");
    printf("[Mensagem:] Escolha uma opção: ");

    int opcaotelaUsuarioEditarExcluir;

    // Loop para garantir que a entrada seja válida
    while (scanf("%d", &opcaotelaUsuarioEditarExcluir) != 1 || (opcaotelaUsuarioEditarExcluir < 1 || opcaotelaUsuarioEditarExcluir > 3)) {
        while (getchar() != '\n');  // Limpa o buffer de entrada
        limparTela();
        printf("\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("| BIBLIOTECA LUNAR - \"EDITAR/EXCLUIR USUÁRIOS\"            DATA: %02d/%02d/%04d  |\n", 
               tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("| [Mensagem:] Você só pode escolher uma das opções:                         |\n");
        printf("|                                                                           |\n");
        printf("|             \"1\" para editar.                                              |\n");
        printf("|                                                                           |\n");
        printf("|             \"2\" para excluir.                                             |\n");
        printf("|                                                                           |\n");
        printf("|             \"3\" para voltar.                                              |\n");
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n\n");
        printf("[Mensagem:] Escolha uma opção: ");
    }

    // Processa a escolha do usuário
    switch (opcaotelaUsuarioEditarExcluir) {
        case 1:
            // Chama a função para editar um usuário
            printf("\n[Mensagem:] Você escolheu editar um usuário.\n");
            // Implementar a lógica de edição de usuário aqui
            break;
        case 2: {
            // Exclui um usuário pelo id
            int numeroUsuario;
            int encontrado = 0;
            Usuario usuarios[100]; // Certifique-se de que o tipo correto está aqui
            int quantidade;

            lerUsuarios("data/usuarios.txt", usuarios, &quantidade);  // Lê todos os usuários

            limparTela();
            printf("\n");
            printf("+---------------------------------------------------------------------------+\n");
            printf("|                                                                           |\n");
            printf("| BIBLIOTECA LUNAR - \"EDITAR/EXCLUIR USUÁRIOS\"            DATA: %02d/%02d/%04d  |\n",
                   tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
            printf("|                                                                           |\n");
            printf("+---------------------------------------------------------------------------+\n");
            printf("|                                                                           |\n");
            printf("| [Mensagem:] Você está na tela de excluir usuários!                        |\n");
            printf("|                                                                           |\n");
            printf("|             Digite o id do usuário que deseja excluir:                    |\n");
            printf("|                                                                           |\n");
            printf("|                                                                           |\n");
            printf("|                                                                           |\n");
            printf("|                                                                           |\n");
            printf("|                                                                           |\n");
            printf("+---------------------------------------------------------------------------+\n\n");
            printf("[Mensagem:] Digite o \"id\" do livro a ser excluído: ");
            scanf("%d", &numeroUsuario);

            // Procura pelo usuário
            for (int i = 0; i < quantidade; i++) {
                if (usuarios[i].idUsuario == numeroUsuario) {
                    encontrado = 1;

                    // Exibe informações do usuário para confirmação
                    limparTela();
                    printf("\n");
                    printf("+---------------------------------------------------------------------------+\n");
                    printf("|                                                                           |\n");
                    printf("| BIBLIOTECA LUNAR - \"EDITAR/EXCLUIR USUÁRIOS\"              DATA: %02d/%02d/%04d  |\n",
                           tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
                    printf("|                                                                           |\n");
                    printf("+---------------------------------------------------------------------------+\n");
                    printf("|                                                                            \n");
                    printf("| [Mensagem:] É este usuário que deve ser excluído:                          \n");
                    printf("|                                                                            \n");
                    printf("|             \"%s\"                                                         \n", usuarios[i].nomeUsuario);
                    printf("|             \"%s\"                                                         \n", usuarios[i].nomeCompleto);
                    printf("|                                                                            \n");
                    printf("|             Tem certeza que deseja apagar este usuário?                    \n");
                    printf("|             Digite \"1\" para Sim ou \"2\" para Não.                          \n");
                    printf("|                                                                            \n");
                    printf("+---------------------------------------------------------------------------+\n\n");

                    int confirmacao;
                    printf("[Mensagem:] Digite a sua escolha: ");
                    scanf("%d", &confirmacao);

                    if (confirmacao == 1) {
                        // Confirma exclusão
                        excluirUsuario("data/usuarios.txt", numeroUsuario);
                        limparTela();
                        printf("\n");
                        printf("+---------------------------------------------------------------------------+\n");
                        printf("|                                                                           |\n");
                        printf("| BIBLIOTECA LUNAR - \"EDITAR/EXCLUIR USUÁRIOS\"              DATA: %02d/%02d/%04d  |\n",
                               tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
                        printf("|                                                                           |\n");
                        printf("+---------------------------------------------------------------------------+\n");
                        printf("|                                                                           |\n");
                        printf("| [Mensagem:] Usuário excluído com sucesso!                                   |\n");
                        printf("|                                                                           |\n");
                        printf("|                                                                           |\n");
                        printf("|                                                                           |\n");
                        printf("|                                                                           |\n");
                        printf("|                                                                           |\n");
                        printf("|                                                                           |\n");
                        printf("|                                                                           |\n");
                        printf("+---------------------------------------------------------------------------+\n\n");
                        printf("[Mensagem:] Pressione ENTER para voltar ao menu.");
                        getchar(); // Aguarda o usuário pressionar Enter
                        getchar(); // Captura o Enter após a leitura da opção
                        telaGerenciadorDeUsuarios();
                    } else {
                        // Cancela exclusão
                        limparTela();
                        printf("\n");
                        printf("+---------------------------------------------------------------------------+\n");
                        printf("|                                                                           |\n");
                        printf("| BIBLIOTECA LUNAR - \"EDITAR/EXCLUIR USUÁRIO\"             DATA: %02d/%02d/%04d  |\n",
                               tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
                        printf("|                                                                           |\n");
                        printf("+---------------------------------------------------------------------------+\n");
                        printf("|                                                                           |\n");
                        printf("| [Mensagem:] A exclusão foi cancelada!                                     |\n");
                        printf("|                                                                           |\n");
                        printf("|                                                                           |\n");
                        printf("|                                                                           |\n");
                        printf("|                                                                           |\n");
                        printf("|                                                                           |\n");
                        printf("|                                                                           |\n");
                        printf("|                                                                           |\n");
                        printf("+---------------------------------------------------------------------------+\n\n");
                        printf("[Mensagem:] Pressione ENTER para voltar ao menu.");
                        getchar(); // Aguarda o usuário pressionar Enter
                        getchar(); // Captura o Enter após a leitura da opção
                        telaGerenciadorDeUsuarios();
                    }
                    break; // Sai do loop após encontrar e tratar o usuário
                }
            }

            if (!encontrado) {
                // Exibe a mensagem de erro
                limparTela();
                printf("\n");
                printf("+---------------------------------------------------------------------------+\n");
                printf("|                                                                           |\n");
                printf("| BIBLIOTECA LUNAR - \"EDITAR/EXCLUIR USUÁRIOS\"            DATA: %02d/%02d/%04d  |\n",
                    tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
                printf("|                                                                           |\n");
                printf("+---------------------------------------------------------------------------+\n");
                printf("|                                                                           |\n");
                printf("| [Mensagem:] O id inserido é inválido, para sua segurança você será        |\n");
                printf("|             redirecionado para o gerenciador de usuários.                 |\n");
                printf("|                                                                           |\n");
                printf("|                                                                           |\n");
                printf("|                                                                           |\n");
                printf("|                                                                           |\n");
                printf("|                                                                           |\n");
                printf("|                                                                           |\n");
                printf("+---------------------------------------------------------------------------+\n\n");
                printf("[Mensagem:] Aguarde 10 segundos... ");
                fflush(stdout);
                sleep(10);  // Espera por 10 segundos
                printf("\n");
            }

            limparTela();
            telaGerenciadorDeUsuarios(); // Retorna ao gerenciamento de usuários
            break;
        }
        case 3:
            limparTela();
            telaGerenciadorDeUsuarios(); // Voltar ao menu gerenciador de usuários
            break;
        default:
            limparTela();
            telaUsuarioEditarExcluir();  // Chama novamente a tela se a opção for inválida
            break;
    }
}
void telaLivroEditarExcluir() {
    // Obtém a data e hora atuais
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| BIBLIOTECA LUNAR - \"EDITAR/EXCLUIR LIVROS\"              DATA: %02d/%02d/%04d  |\n", 
           tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| [Mensagem:] Escolha o que deseja fazer:                                   |\n");
    printf("|                                                                           |\n");
    printf("|             \"1\" para editar.                                              |\n");
    printf("|                                                                           |\n");
    printf("|             \"2\" para excluir.                                             |\n");
    printf("|                                                                           |\n");
    printf("|             \"3\" para voltar.                                              |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n\n");
    printf("[Mensagem:] Escolha uma opção: ");

    int opcaotelaLivroEditarExcluir;

    // Loop para garantir que a entrada seja válida
    while (scanf("%d", &opcaotelaLivroEditarExcluir) != 1 || (opcaotelaLivroEditarExcluir < 1 || opcaotelaLivroEditarExcluir > 3)) {
        while (getchar() != '\n');  // Limpa o buffer de entrada

        // Exibe o menu novamente em caso de erro
        limparTela();
        printf("\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("| BIBLIOTECA LUNAR - \"EDITAR/EXCLUIR LIVROS\"              DATA: %02d/%02d/%04d  |\n", 
               tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("| [Mensagem:] Você só pode escolher uma das opções:                         |\n");
        printf("|                                                                           |\n");
        printf("|             \"1\" para editar.                                              |\n");
        printf("|                                                                           |\n");
        printf("|             \"2\" para excluir.                                             |\n");
        printf("|                                                                           |\n");
        printf("|             \"3\" para voltar.                                              |\n");
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n\n");
        printf("[Mensagem:] Escolha uma opção: ");
    }

    // Processa a escolha do usuário
    switch (opcaotelaLivroEditarExcluir) {
        case 1:
            // Chama a função para editar um livro
            printf("\n[Mensagem:] Você escolheu editar um livro.\n");
            // Implementar a lógica de edição de livro aqui
            break;
        case 2: {
    // Exclui um livro pelo número
    int numeroLivro;
    int encontrado = 0;
    Livro livros[100];
    int quantidade;

    lerLivros("data/livros.txt", livros, &quantidade);  // Lê todos os livros para exibir o título

    limparTela();
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| BIBLIOTECA LUNAR - \"EDITAR/EXCLUIR LIVROS\"              DATA: %02d/%02d/%04d  |\n",
           tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| [Mensagem:] Você está na tela de excluir livros!                          |\n");
    printf("|                                                                           |\n");
    printf("|             Digite o id do livro que deseja excluir:                      |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n\n");
    printf("[Mensagem:] Digite o \"id\" do livro a ser excluído: ");
    scanf("%d", &numeroLivro);

    // Procura pelo livro
    for (int i = 0; i < quantidade; i++) {
        if (livros[i].numeroLivro == numeroLivro) {
            encontrado = 1;

            // Exibe o título do livro para confirmação
            limparTela();
            printf("\n");
            printf("+---------------------------------------------------------------------------+\n");
            printf("|                                                                           |\n");
            printf("| BIBLIOTECA LUNAR - \"EDITAR/EXCLUIR LIVROS\"              DATA: %02d/%02d/%04d  |\n",
                   tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
            printf("|                                                                           |\n");
            printf("+---------------------------------------------------------------------------+\n");
            printf("|                                                                            \n");
            printf("| [Mensagem:] Título do livro a ser excluído:                                \n");
            printf("|                                                                            \n");
            printf("|             \"%s\"                                                         \n", livros[i].tituloLivro);
            printf("|                                                                            \n");
            printf("|             Tem certeza que deseja apagar este livro?                      \n");
            printf("|             Digite \"1\" para Sim ou \"2\" para Não.                          \n");
            printf("|                                                                            \n");
            printf("|                                                                            \n");
            printf("+---------------------------------------------------------------------------+\n\n");

            int confirmacao;
            printf("[Mensagem:] Digite a sua escolha: ");
            scanf("%d", &confirmacao);

            if (confirmacao == 1) {
                // Confirma exclusão
                excluirLivro("data/livros.txt", numeroLivro);
                limparTela();
                printf("\n");
                printf("+---------------------------------------------------------------------------+\n");
                printf("|                                                                           |\n");
                printf("| BIBLIOTECA LUNAR - \"EDITAR/EXCLUIR LIVROS\"              DATA: %02d/%02d/%04d  |\n",
                       tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
                printf("|                                                                           |\n");
                printf("+---------------------------------------------------------------------------+\n");
                printf("|                                                                           |\n");
                printf("| [Mensagem:] Livro excluído com sucesso!                                   |\n");
                printf("|                                                                           |\n");
                printf("|                                                                           |\n");
                printf("|                                                                           |\n");
                printf("|                                                                           |\n");
                printf("|                                                                           |\n");
                printf("|                                                                           |\n");
                printf("|                                                                           |\n");
                printf("+---------------------------------------------------------------------------+\n\n");
                printf("[Mensagem:] Pressione ENTER para voltar ao menu.");
                getchar(); // Aguarda o usuário pressionar Enter
                getchar(); // Captura o Enter após a leitura da opção
                telaGerenciadorDeLivros();
            } else {
                // Cancela exclusão
                limparTela();
                printf("\n");
                printf("+---------------------------------------------------------------------------+\n");
                printf("|                                                                           |\n");
                printf("| BIBLIOTECA LUNAR - \"EDITAR/EXCLUIR LIVROS\"              DATA: %02d/%02d/%04d  |\n",
                       tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
                printf("|                                                                           |\n");
                printf("+---------------------------------------------------------------------------+\n");
                printf("|                                                                           |\n");
                printf("| [Mensagem:] A exclusão foi cancelada!                                     |\n");
                printf("|                                                                           |\n");
                printf("|                                                                           |\n");
                printf("|                                                                           |\n");
                printf("|                                                                           |\n");
                printf("|                                                                           |\n");
                printf("|                                                                           |\n");
                printf("|                                                                           |\n");
                printf("+---------------------------------------------------------------------------+\n\n");
                printf("[Mensagem:] Pressione ENTER para voltar ao menu.");
                getchar(); // Aguarda o usuário pressionar Enter
                getchar(); // Captura o Enter após a leitura da opção
                limparTela();
                telaGerenciadorDeLivros();
            }

            break;
        }
    }

    if (!encontrado) {
        // Exibe a mensagem de erro e redireciona para o gerenciador de livros
        limparTela();
        printf("\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("| BIBLIOTECA LUNAR - \"EDITAR/EXCLUIR LIVROS\"              DATA: %02d/%02d/%04d  |\n",
               tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("| [Mensagem:] O id inserido é inválido, para sua segurança você será        |\n");
        printf("|             redirecionado para o gerenciador de livros.                   |\n");
        printf("|                                                                           |\n");
        printf("|                                                                           |\n");
        printf("|                                                                           |\n");
        printf("|                                                                           |\n");
        printf("|                                                                           |\n");
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n\n");
        printf("[Mensagem:] Aguarde 10 segundos... ");
        fflush(stdout);

        sleep(10);  // Espera por 10 segundos
        printf("\n");
    }

    // Retorna ao gerenciamento de livros
    limparTela();
    telaGerenciadorDeLivros();
    break;
}
        case 3:
            limparTela();
            telaGerenciadorDeLivros(); // Voltar ao menu gerenciador de livros
            break;
        default:
            limparTela();
            telaLivroEditarExcluir();  // Chama novamente a tela se a opção for inválida
            break;
    }
}
void telaCadastroUsuario(const char *nomeArquivo) {
    Usuario novoUsuario;

    // Obtém um ID disponível
    novoUsuario.idUsuario = obterIdDisponivel(nomeArquivo);

    // Adicione esta linha antes do uso de 'tm'
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    // Coleta de informações do usuário
    limparTela();
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| BIBLIOTECA LUNAR - \"CRIAÇÃO DE USUÁRIOS\"                DATA: %02d/%02d/%04d  |\n",
           tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| [Mensagem:] Você está na tela de criação de usuário!                      |\n");
    printf("|                                                                           |\n");
    printf("|             Digite o nome de usuário:                                     |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n\n");
    printf("[Mensagem:] Nome de usuário: ");
    fgets(novoUsuario.nomeUsuario, MAX_NOME_USUARIO, stdin);
    novoUsuario.nomeUsuario[strcspn(novoUsuario.nomeUsuario, "\n")] = 0;

    limparTela();
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| BIBLIOTECA LUNAR - \"CRIAÇÃO DE USUÁRIOS\"                DATA: %02d/%02d/%04d  |\n",
           tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| [Mensagem:] Você está na tela de criação de usuário!                      |\n");
    printf("|                                                                           |\n");
    printf("|             Digite a senha desejada:                                      |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n\n");
    printf("[Mensagem:] Senha: ");
    fgets(novoUsuario.senhaUsuario, MAX_SENHA, stdin);
    novoUsuario.senhaUsuario[strcspn(novoUsuario.senhaUsuario, "\n")] = 0;

    limparTela();
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| BIBLIOTECA LUNAR - \"CRIAÇÃO DE USUÁRIOS\"                DATA: %02d/%02d/%04d  |\n",
           tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| [Mensagem:] Você está na tela de criação de usuário!                      |\n");
    printf("|                                                                           |\n");
    printf("|             Digite seu nome completo:                                     |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n\n");
    printf("[Mensagem:] Nome de usuário: ");
    fgets(novoUsuario.nomeCompleto, MAX_NOME_COMPLETO, stdin);
    novoUsuario.nomeCompleto[strcspn(novoUsuario.nomeCompleto, "\n")] = 0;

    limparTela();
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| BIBLIOTECA LUNAR - \"CRIAÇÃO DE USUÁRIOS\"                DATA: %02d/%02d/%04d  |\n",
           tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| [Mensagem:] Você está na tela de criação de usuário!                      |\n");
    printf("|                                                                           |\n");
    printf("|             Digite o nome de usuário:                                     |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n\n");
    printf("[Mensagem:] CPF: ");
    fgets(novoUsuario.cpfUsuario, MAX_CPF, stdin);
    novoUsuario.cpfUsuario[strcspn(novoUsuario.cpfUsuario, "\n")] = 0;

    // Inicializa os outros campos
    novoUsuario.reservaUsuario = 0;
    novoUsuario.pontosUsuario = 0;
    novoUsuario.multaUsuario = 0.0f;

    // Cria o usuário
    criarUsuarios(nomeArquivo, novoUsuario);
    limparTela();
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| BIBLIOTECA LUNAR - \"CRIAÇÃO DE USUÁRIOS\"                DATA: %02d/%02d/%04d  |\n",
            tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| [Mensagem:] Usuário cadastrado com sucesso!                               |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n\n");
    printf("[Mensagem:] Pressione ENTER para voltar ao menu.");
    getchar(); // Aguarda o usuário pressionar Enter
    getchar(); // Captura o Enter após a leitura da opção
    telaPrincipal();
}

void telaUsuario(Livro *livros, int quantidade) {
    // Obtém a data e hora atuais
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    limparTela();
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| BIBLIOTECA LUNAR - \"MENU DO USUÁRIO\"                   DATA: %02d/%02d/%04d  |\n", 
           tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| 1. Livros Disponíveis.                                                    |\n");
    printf("|                                                                           |\n");
    printf("| 2. Reservar Livros.                                                       |\n");
    printf("|                                                                           |\n");
    printf("| 3. Livros Reservados.                                                     |\n");
    printf("|                                                                           |\n");
    printf("| 4. Liberar Reservas.                                                      |\n");
    printf("|                                                                           |\n");
    printf("| 5. Multas.                                                                |\n");
    printf("|                                                                           |\n");
    printf("| 6. Sair.                                                                  |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n\n");
    printf("[Mensagem:] Digite a opção desejada: ");

    int opcaoUsuario;

    // Valida a opção de entrada
    while (scanf("%d", &opcaoUsuario) != 1 || (opcaoUsuario < 1 || opcaoUsuario > 6)) {
        while (getchar() != '\n');  // Limpa o buffer de entrada
        limparTela();
        printf("\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("| BIBLIOTECA LUNAR - \"MENU DO USUÁRIO\"                   DATA: %02d/%02d/%04d  |\n", 
               tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("| 1. Livros Disponíveis.                                                    |\n");
        printf("|                                                                           |\n");
        printf("| 2. Reservar Livros.                                                       |\n");
        printf("|                                                                           |\n");
        printf("| 3. Livros Reservados.                                                     |\n");
        printf("|                                                                           |\n");
        printf("| 4. Liberar Reservas.                                                      |\n");
        printf("|                                                                           |\n");
        printf("| 5. Multas.                                                                |\n");
        printf("|                                                                           |\n");
        printf("| 6. Sair.                                                                  |\n");
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n\n");
        printf("[Mensagem:] Escolha uma opção válida: ");
    }

    switch (opcaoUsuario) {
        case 1:
            // Chama a função para exibir livros disponíveis
            limparTela();
            mostrarLivrosDisponiveis(livros, quantidade);
            break;
        case 2:
            // Chama a função para reservar livros
            limparTela();
            reservarLivro(livros, quantidade);
            break;
        case 3:
            // Chama a função para exibir livros reservados
            limparTela();
            mostrarLivrosReservados(livros, quantidade);
            break;
        case 4:
            // Chama a função para liberar reservas
            limparTela();
            telaLiberarReserva(livros, quantidade);
            break;
        case 5:
            // Chama a função para exibir multas
            limparTela();
            mostrarMulta(livros, quantidade);
            break;
        case 6:
            // Sai do sistema
            limparTela();
            printf("\n");
            printf("+---------------------------------------------------------------------------+\n");
            printf("|                                                                           |\n");
            printf("| BIBLIOTECA LUNAR - \"SAIR\"                             DATA: %02d/%02d/%04d  |\n", 
                   tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
            printf("|                                                                           |\n");
            printf("+---------------------------------------------------------------------------+\n\n");
            printf("[Mensagem:] Você escolheu sair do sistema. Até mais!\n\n\n");
            return;
        default:
            limparTela();
            telaUsuario(livros, quantidade);  // Chama novamente a função caso a opção seja inválida
            break;
    }
}

void mostrarLivrosDisponiveis(Livro *livros, int quantidade) {
    printf("\n+---------------------------------------------------------------------------+\n");
    printf("|                           LIVROS DISPONÍVEIS                             |\n");
    printf("+---------------------------------------------------------------------------+\n");

    int encontrou = 0;  // Para verificar se há livros disponíveis

    for (int i = 0; i < quantidade; i++) {
        if (livros[i].reservaLivro == 0) {  // Verifica se o livro não está reservado
            printf("| ID: %d\n", livros[i].numeroLivro);
            printf("| Título: %s\n", livros[i].tituloLivro);
            printf("| Autor: %s\n", livros[i].autorLivro);
            printf("| Ano: %d\n", livros[i].anoLivro);
            printf("+---------------------------------------------------------------------------+\n");
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("| Nenhum livro disponível no momento.                                       |\n");
        printf("+---------------------------------------------------------------------------+\n");
    }

    printf("\nPressione ENTER para voltar ao menu.");
    getchar();  // Pausa para o usuário
    getchar();  // Captura Enter
}

void processarReservaLivro(Livro *livro) {
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

void reservarLivro(Livro *livros, int quantidade) {
    printf("\nDigite o ID do livro que deseja reservar: ");
    int id;
    scanf("%d", &id);
    getchar();  // Limpa o buffer

    int encontrado = 0;

    for (int i = 0; i < quantidade; i++) {
        if (livros[i].numeroLivro == id) {
            encontrado = 1;
            if (livros[i].reservaLivro == 0) {  // Se o livro não estiver reservado
                processarReservaLivro(&livros[i]);  // Renomeada para evitar conflito
                printf("Livro reservado com sucesso!\n");
            } else {
                printf("Este livro já está reservado.\n");
            }
            break;
        }
    }

    if (!encontrado) {
        printf("Livro com ID %d não encontrado.\n", id);
    }

    printf("\nPressione ENTER para voltar ao menu.");
    getchar();  // Pausa para o usuário
}

void mostrarLivrosReservados(Livro *livros, int quantidade) {
    printf("\n+---------------------------------------------------------------------------+\n");
    printf("|                           LIVROS RESERVADOS                               |\n");
    printf("+---------------------------------------------------------------------------+\n");

    int encontrou = 0;

    for (int i = 0; i < quantidade; i++) {
        if (livros[i].reservaLivro == 1) {  // Verifica se o livro está reservado
            printf("| ID: %d\n", livros[i].numeroLivro);
            printf("| Título: %s\n", livros[i].tituloLivro);
            printf("| Data da Reserva: %s\n", livros[i].dataReserva);
            printf("| Prazo de Devolução (em dias): %d\n", livros[i].diasParaLiberar);
            printf("+---------------------------------------------------------------------------+\n");
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("| Nenhum livro reservado no momento.                                        |\n");
        printf("+---------------------------------------------------------------------------+\n");
    }

    printf("\nPressione ENTER para voltar ao menu.");
    getchar();  // Pausa para o usuário
    getchar();  // Captura Enter
}
void telaLiberarReserva(Livro *livros, int quantidade) {
    // Exibe os livros reservados
    printf("\n+---------------------------------------------------------------------------+\n");
    printf("|                             LIBERAR RESERVA                               |\n");
    printf("+---------------------------------------------------------------------------+\n");

    int encontrou = 0;

    // Mostra apenas livros reservados
    for (int i = 0; i < quantidade; i++) {
        if (livros[i].reservaLivro == 1) {  // Verifica se o livro está reservado
            printf("| ID: %d\n", livros[i].numeroLivro);
            printf("| Título: %s\n", livros[i].tituloLivro);
            printf("| Autor: %s\n", livros[i].autorLivro);
            printf("| Ano: %d\n", livros[i].anoLivro);
            printf("| Data de Reserva: %s\n", livros[i].dataReserva);
            printf("+---------------------------------------------------------------------------+\n");
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("| Nenhum livro reservado no momento.                                        |\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("\nPressione ENTER para voltar ao menu.");
        getchar();  // Pausa para o usuário
        return;  // Volta ao menu sem tentar liberar reserva
    }

    // Solicita o ID do livro para liberar reserva
    printf("\nDigite o ID do livro que deseja liberar a reserva: ");
    int id;
    scanf("%d", &id);
    getchar();  // Limpa o buffer

    encontrou = 0;

    // Libera a reserva do livro escolhido
    for (int i = 0; i < quantidade; i++) {
        if (livros[i].numeroLivro == id) {
            encontrou = 1;
            if (livros[i].reservaLivro == 1) {  // Se o livro estiver reservado
                liberarLivro(&livros[i]);  // Chama a função para liberar o livro
                printf("Livro \"%s\" devolvido com sucesso!\n", livros[i].tituloLivro);
            } else {
                printf("Este livro não está reservado.\n");
            }
            break;
        }
    }

    if (!encontrou) {
        printf("Livro com ID %d não encontrado.\n", id);
    }

    printf("\nPressione ENTER para voltar ao menu.");
    getchar();  // Pausa para o usuário
}

void mostrarMulta(Livro *livros, int quantidade) {
    printf("\n+---------------------------------------------------------------------------+\n");
    printf("|                           CONSULTAR MULTAS                                |\n");
    printf("+---------------------------------------------------------------------------+\n");

    int encontrou = 0;
    float multaTotal = 0.0f;

    for (int i = 0; i < quantidade; i++) {
        if (livros[i].reservaLivro == 1) {  // Verifica se o livro está reservado
            float multa = calcularMulta(&livros[i]);
            if (multa > 0) {
                printf("| ID: %d\n", livros[i].numeroLivro);
                printf("| Título: %s\n", livros[i].tituloLivro);
                printf("| Multa atual: R$%.2f\n", multa);
                printf("+---------------------------------------------------------------------------+\n");
                encontrou = 1;
                multaTotal += multa;
            }
        }
    }

    if (!encontrou) {
        printf("| Nenhum livro com multa no momento.                                        |\n");
        printf("+---------------------------------------------------------------------------+\n");
    } else {
        printf("| Multa total: R$%.2f\n", multaTotal);
        printf("+---------------------------------------------------------------------------+\n");
    }

    printf("\nPressione ENTER para voltar ao menu.");
    getchar();  // Pausa para o usuário
    getchar();  // Captura Enter
}

void mostrarUsuariosComMulta(Usuario *usuarios, int quantidade) {
    int encontrouMulta = 0;
    
    // Cabeçalho da tela
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("| BIBLIOTECA LUNAR - \"USUÁRIOS COM MULTAS\"                                |\n");
    printf("+---------------------------------------------------------------------------+\n");

    // Loop para listar os usuários que possuem multas
    for (int i = 0; i < quantidade; i++) {
        if (usuarios[i].multaUsuario > 0) {  // Verifica se o usuário tem multa
            encontrouMulta = 1;
            printf("| Usuário......: %s\n", usuarios[i].nomeUsuario);
            printf("| Nome Completo: %s\n", usuarios[i].nomeCompleto);
            printf("| CPF..........: %s\n", usuarios[i].cpfUsuario);
            printf("| Multa........: R$ %.2f\n", usuarios[i].multaUsuario);
            printf("+---------------------------------------------------------------------------+\n");
        }
    }

    if (!encontrouMulta) {
        printf("| Nenhum usuário com multas no momento.                                     |\n");
        printf("+---------------------------------------------------------------------------+\n");
    }

    // Opção de retorno ao menu
    printf("\nPressione ENTER para voltar ao menu.");
    getchar();  // Pausa para o administrador
}
void zerarMultaUsuario(Usuario *usuarios, int quantidade) {
    int encontrouMulta = 0;

    // Cabeçalho da tela
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("| BIBLIOTECA LUNAR - \"GERENCIAR MULTAS\"                                   |\n");
    printf("+---------------------------------------------------------------------------+\n");

    // Listar os usuários que possuem multas
    for (int i = 0; i < quantidade; i++) {
        if (usuarios[i].multaUsuario > 0) {  // Verifica se o usuário tem multa
            encontrouMulta = 1;
            printf("| ID: %d\n", i + 1);  // Mostra o ID do usuário (pode ser o índice do array)
            printf("| Usuário......: %s\n", usuarios[i].nomeUsuario);
            printf("| Nome Completo: %s\n", usuarios[i].nomeCompleto);
            printf("| CPF..........: %s\n", usuarios[i].cpfUsuario);
            printf("| Multa........: R$ %.2f\n", usuarios[i].multaUsuario);
            printf("+---------------------------------------------------------------------------+\n");
        }
    }

    if (!encontrouMulta) {
        printf("| Nenhum usuário com multas no momento.                                     |\n");
        printf("+---------------------------------------------------------------------------+\n");
        return;
    }

    // Solicita o ID do usuário para zerar a multa
    int id;
    printf("Digite o ID do usuário para marcar a multa como paga: ");
    scanf("%d", &id);
    getchar();  // Limpa o buffer

    // Verifica se o ID é válido
    if (id > 0 && id <= quantidade && usuarios[id - 1].multaUsuario > 0) {
        // Zera a multa do usuário
        usuarios[id - 1].multaUsuario = 0.0f;
        printf("\nMulta do usuário '%s' foi zerada com sucesso!\n", usuarios[id - 1].nomeUsuario);
    } else {
        printf("\nID inválido ou o usuário selecionado não possui multas.\n");
    }

    printf("\nPressione ENTER para voltar ao menu.");
    getchar();  // Pausa para o administrador
}
