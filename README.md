# Biblioteca em C 📚🌕

## Sobre o Projeto
O **Biblioteca Lunar** é um sistema de gerenciamento de bibliotecas desenvolvido em C. Ele foi projetado para ser um software simples e funcional que permite a administração de livros e usuários em uma biblioteca, oferecendo recursos como cadastro, edição e remoção de livros, reservas e cálculo de multas. Utiliza arquivos de texto para armazenar dados e pode ser executado em qualquer sistema compatível com C.

## Organização dos Arquivos

A estrutura do projeto está organizada em diversos diretórios para separar as diferentes responsabilidades do código:

### Diretórios:

- **/src** - Contém os arquivos fonte `.c` que implementam as funcionalidades do sistema.
  - **livro.c** - Implementa as operações de gerenciamento de livros (cadastro, edição, remoção, etc).
  - **usuario.c** - Gerencia as funcionalidades relacionadas aos usuários (cadastro, exclusão, autenticação, etc).
  - **sistema.c** - Contém funções relacionadas à interface do sistema e autenticação (login de usuário e administrador, navegação nos menus, etc).
  - **main.c** - Contém o ponto de entrada principal do programa e chama as funções apropriadas para o fluxo do sistema.
  
- **/include** - Contém os arquivos de cabeçalho `.h` que definem as estruturas e as funções utilizadas no projeto.
  - **livro.h** - Declara a estrutura `Livro` e as funções relacionadas à gestão de livros.
  - **usuario.h** - Declara a estrutura `Usuario` e as funções associadas à gestão de usuários.
  - **sistema.h** - Declara funções que manipulam a lógica do sistema, telas de interface e autenticação.

- **/data** - Diretório que contém os arquivos de dados utilizados para armazenar permanentemente as informações da biblioteca.
  - **livros.txt** - Armazena as informações dos livros da biblioteca.
  - **usuarios.txt** - Armazena os dados dos usuários registrados no sistema.

- **/obj** - Contém os arquivos objeto (*.o*) gerados durante a compilação do projeto.

- **/bin** - Local onde o executável principal do sistema, após a compilação, é armazenado.
  - **biblioteca_lunar.exe** - Arquivo executável do sistema.

- **/output** - Diretório que contém o arquivo executável final após a compilação.
  - **main.exe** - Executável final do sistema.

- **Makefile** - Arquivo de automação que contém as instruções para compilar o sistema e gerar os arquivos objetos e executáveis.

---

## Funcionalidades Detalhadas

### 1. Gerenciamento de Livros

O módulo de gerenciamento de livros permite que o administrador adicione, edite, remova e exiba detalhes sobre os livros na biblioteca. Os livros podem ser reservados pelos usuários e o sistema calcula automaticamente as multas por atrasos na devolução.

#### Funções principais:
- **criarLivros(const char *nomeArquivo, Livro livro)**: Adiciona um novo livro ao arquivo de dados `livros.txt`.
- **lerLivros(const char *nomeArquivo, Livro *livros, int *quantidade)**: Lê os dados de todos os livros armazenados no arquivo.
- **excluirLivro(const char *nomeArquivo, int numeroLivro)**: Remove um livro do arquivo de dados com base no seu número identificador.
- **reservarLivro(Livro *livro)**: Marca um livro como reservado e grava a data de reserva.
- **calcularMulta(Livro *livro)**: Calcula a multa do livro com base nos dias de atraso na devolução.
- **liberarLivro(Livro *livro)**: Marca o livro como devolvido, liberando-o para outra reserva.

### 2. Gerenciamento de Usuários

O sistema permite o cadastro de usuários, que podem fazer login e gerenciar suas reservas. Os usuários podem ver os livros disponíveis, reservar livros e consultar suas multas em caso de atraso na devolução.

#### Funções principais:
- **criarUsuarios(const char *nomeArquivo, Usuario usuario)**: Adiciona um novo usuário ao arquivo `usuarios.txt`.
- **lerUsuarios(const char *nomeArquivo, Usuario *usuarios, int *quantidade)**: Lê e carrega os usuários registrados a partir do arquivo de dados.
- **excluirUsuario(const char *nomeArquivo, int idUsuario)**: Remove um usuário com base no seu ID.
- **obterIdDisponivel(const char *nomeArquivo)**: Retorna o próximo ID disponível para o cadastro de novos usuários.

### 3. Sistema de Autenticação

O sistema diferencia entre administradores e usuários, com permissões distintas. Administradores podem gerenciar livros e usuários, enquanto os usuários podem apenas fazer reservas e acompanhar suas multas.

#### Funções principais:
- **telaLoginUsuario()**: Exibe a tela de login para o usuário e solicita suas credenciais.
- **validarUsuarioUsuario(const char *usuarioUsuario, const char *senhaUsuario)**: Verifica se o nome de usuário e a senha estão corretos para o login de um usuário comum.
- **telaConfirmarAutenticacaoAdministrador()**: Exibe a tela de login para o administrador.
- **validarUsuarioAdministrador(const char *usuarioAdmin, const char *senhaAdmin)**: Valida o nome de usuário e senha do administrador.

### 4. Interface do Sistema

O sistema oferece várias telas para facilitar a navegação entre as funcionalidades. Existem telas específicas para gerenciar livros, usuários, exibir multas e reservas.

#### Funções principais:
- **telaPrincipal()**: Tela principal onde o usuário ou administrador escolhe a ação que deseja realizar.
- **telaAdministrativa()**: Menu de opções administrativas para gerenciar livros e usuários.
- **mostrarLivrosDisponiveis(Livro *livros, int quantidade)**: Exibe uma lista de todos os livros disponíveis para reserva.
- **telaGerenciadorDeLivros()**: Interface que permite ao administrador gerenciar o cadastro, edição e exclusão de livros.
- **telaGerenciadorDeUsuarios()**: Interface para a gestão de usuários (cadastro, exclusão).
- **mostrarMulta(Livro *livros, int quantidade)**: Exibe as multas associadas aos livros em atraso.

---

## Como Executar o Projeto

### Pré-requisitos

- **Compilador C (GCC ou equivalente)**: Para compilar o código.
- **Make**: Para automação do processo de compilação.

### Passos para Compilar e Executar

1. Clone o repositório:

    ```bash
    git clone https://github.com/seu-usuario/biblioteca-lunar.git
    ```

2. Acesse o diretório do projeto:

    ```bash
    cd biblioteca-lunar
    ```

3. Compile o projeto usando o Makefile:

    ```bash
    make all
    ```

4. Execute o sistema:

    ```bash
    ./output/main.exe
    ```

### Limpando Arquivos Gerados

Para limpar os arquivos objeto e executáveis criados durante a compilação, use o comando:

```bash
make clean
```

---

## Licença

Este projeto está licenciado sob a [MIT License](LICENSE).

---

## Contribuição

Se você quiser contribuir com este projeto, sinta-se à vontade para abrir uma **issue** ou enviar um **pull request** com melhorias, correções ou novas funcionalidades. Toda ajuda é bem-vinda!

---

Esse README detalha a organização do sistema **Biblioteca Lunar**, suas funcionalidades e como utilizá-lo. Ele é ideal para ser publicado em um repositório do GitHub, facilitando a navegação para quem deseja colaborar ou utilizar o projeto.
