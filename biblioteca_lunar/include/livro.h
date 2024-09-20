#ifndef LIVRO_H
#define LIVRO_H

typedef struct {
    int numeroLivro;
    char tituloLivro[100];
    char autorLivro[100];
    int anoLivro;
    int paginas;            // Novo campo para a quantidade de páginas do livro
    int reservaLivro;        // 0 = disponível, 1 = reservado
    char dataReserva[11];    // Data no formato dd/mm/yyyy
    int diasParaLiberar;     // Quantidade de dias para devolver o livro
    float multa;             // Multa por atraso
} Livro;

void criarLivros(const char *nomeArquivo, Livro livro);
void lerLivros(const char *nomeArquivo, Livro *livros, int *quantidade);
void excluirLivro(const char *nomeArquivo, int numeroLivro);
int obterNumeroDisponivel(const char *nomeArquivo);
void reservarLivro(Livro *livro);
float calcularMulta(Livro *livro);
void liberarLivro(Livro *livro);
void exibirDetalhesLivro(Livro *livro);

#endif // LIVRO_H