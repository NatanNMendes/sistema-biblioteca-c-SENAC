// sistema.h

#ifndef SISTEMA_H
#define SISTEMA_H

extern const char* ADMIN_USERNAME;
extern const char* ADMIN_PASSWORD;
extern const char* USUARIO_USERNAME;
extern const char* USUARIO_PASSWORD;

void telaPrincipal();
void telaInicial();
void telaAdministrativa();
void telaCodigoCadastro();
void telaGerenciadorDeUsuarios();
void telaGerenciadorDeLivros();
void telaConfirmarAutenticacaoAdministrador();
void telaConfirmarAutenticacaoUsuario();
void telaErroLogin();
void gerarCodigoCadastro();
void limparTela();
void telaLoginUsuario();
void telaValidaCodigoUsuario();
void telaUsuarioEditarExcluir();
void telaLivroEditarExcluir();
void telaCadastroUsuario(const char *nomeArquivo);
void telaUsuario(Livro *livros, int quantidade);
void mostrarLivrosDisponiveis(Livro *livros, int quantidade);
void reservarLivro(Livro *livros, int quantidade);
void mostrarLivrosReservados(Livro *livros, int quantidade);
void telaLiberarReserva(Livro *livros, int quantidade);
void mostrarMulta(Livro *livros, int quantidade);
void processarReservaLivro(Livro *livro);
void mostrarUsuariosComMulta(Usuario *usuarios, int quantidade);

int validarUsuarioAdministrador(const char *usuarioAdmin, const char *senhaAdmin);
int validarUsuarioUsuario(const char *usuarioUsuario, const char *senhaUsuario);

#endif // SISTEMA_H
