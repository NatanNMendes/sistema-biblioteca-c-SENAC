#ifndef USUARIO_H

#define MAX_NOME_USUARIO 50
#define MAX_NOME_COMPLETO 100
#define MAX_SENHA 20
#define MAX_CPF 15
#define MAX_USUARIOS 100

typedef struct {
    int idUsuario;
    char nomeUsuario[MAX_NOME_USUARIO];
    char senhaUsuario[MAX_SENHA];
    char nomeCompleto[MAX_NOME_COMPLETO];
    char cpfUsuario[MAX_CPF];
    int reservaUsuario;
    int pontosUsuario;
    float multaUsuario;
} Usuario;

void criarUsuarios(const char *nomeArquivo, Usuario usuario);
void lerUsuarios(const char *nomeArquivo, Usuario *usuarios, int *quantidade);
void excluirUsuario(const char *nomeArquivo, int idUsuario);
int obterIdDisponivel(const char *nomeArquivo);

#endif // USUARIO_H