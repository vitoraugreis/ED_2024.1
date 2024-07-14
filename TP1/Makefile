# Trabalho Prático 1

## Diretórios
BIN_DIR = bin
INC_DIR = include
OBJ_DIR = obj
SRC_DIR = src
DOC_DIR = docs

## Compilador
CC = gcc
CFLAGS = -std=gnu11 -Wall

## Arquivo Final
TP = $(BIN_DIR)/tp1.out
INPUT = $(BIN_DIR)/input.out

## Objetos compilação
OBJS_TP = $(OBJ_DIR)/TP1.o
OBJS_INP = $(OBJ_DIR)/inputGen.o

## Regras de Compilação
$(TP): $(OBJS_TP)
	$(CC) $(CFLAGS) -o $(TP) $(OBJS_TP)

$(INPUT): $(OBJS_INP)
	$(CC) $(CFLAGS) -o $(INPUT) $(OBJS_INP)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $^

all: $(TP)

clear:
	rm $(OBJ_DIR)/* $(BIN_DIR)/*

teste: $(TP)
	clear
	./$(TP)

input: $(INPUT)
	clear
	./$(INPUT) > $(DOC_DIR)/input.txt
