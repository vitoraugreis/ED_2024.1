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
TARGET = $(BIN_DIR)/pa4.out

# Objetos para compilação
OBJS = $(OBJ_DIR)/minHeap.o $(OBJ_DIR)/unionFind.o $(OBJ_DIR)/pa4.o

## REGRAS DE COMPILAÇÃO
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

all: $(TARGET)

clear:
	rm $(OBJ_DIR)/* $(BIN_DIR)/pa4.out

valgrind: $(TARGET)
	clear
	valgrind -s --leak-check=yes ./$(TARGET) -d 1 2

run: $(TARGET)
	clear
	./$(BIN_DIR)/pa4.out