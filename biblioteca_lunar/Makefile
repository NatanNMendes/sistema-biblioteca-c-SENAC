# Nome do compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -g

# Nome do executável
TARGET = biblioteca_lunar

# Diretórios
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Arquivos de código-fonte
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/sistema.c $(SRC_DIR)/usuario.c $(SRC_DIR)/livro.c

# Arquivos objeto
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/sistema.o $(OBJ_DIR)/usuario.o $(OBJ_DIR)/livro.o

# Caminho para os cabeçalhos
INCLUDES = -Iinclude

# Regras principais
all: $(TARGET)

# Geração do executável
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(BIN_DIR)/$(TARGET)

# Compilação dos arquivos objeto
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/sistema.o: $(SRC_DIR)/sistema.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/sistema.c -o $(OBJ_DIR)/sistema.o

$(OBJ_DIR)/usuario.o: $(SRC_DIR)/usuario.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/usuario.c -o $(OBJ_DIR)/usuario.o

$(OBJ_DIR)/livro.o: $(SRC_DIR)/livro.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/livro.c -o $(OBJ_DIR)/livro.o

# Limpeza dos arquivos objeto e binário
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Limpeza completa
dist-clean: clean
	rm -f *~ $(SRC_DIR)/*~
