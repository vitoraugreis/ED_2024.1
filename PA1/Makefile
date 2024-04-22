# Atividade Prática 1

# Diretórios
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INC_DIR = include

# Compilador
CC = gcc
CFLAGS = -std=gnu11 -Wall -lrt

# Arquivo final
TARGET = $(BIN_DIR)/pa1.out

# Objetos para compilação
OBJS = $(OBJ_DIR)/PA1.o

## REGRAS DE COMPILAÇÃO
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $^

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

all: $(TARGET)