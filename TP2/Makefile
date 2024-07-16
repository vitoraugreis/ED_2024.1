# Atividade Prática 2

# Diretórios
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INC_DIR = include

# Compilador
CC = g++
CFLAGS = -std=c++17 -Wall -I$(INC_DIR)

# Arquivo final
TARGET = $(BIN_DIR)/tp2.out

# Cabeçalhos
HDRS = $(INC_DIR)/Lista.hpp $(INC_DIR)/GrafoLA.hpp

# Objetos para compilação
OBJS = $(OBJ_DIR)/Lista.o $(OBJ_DIR)/GrafoLA.o $(OBJ_DIR)/tp2.o

## REGRAS DE COMPILAÇÃO
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

all: $(TARGET)