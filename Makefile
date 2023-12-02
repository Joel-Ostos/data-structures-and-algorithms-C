CC = gcc
CFLAGS = -Wall -g
SRC_DIR = src
TEST_DIR = src/test
OBJ_DIR = obj
BIN_DIR = bin

SOURCES = $(wildcard $(TEST_DIR)/*.c)
OBJECTS = $(patsubst $(TEST_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))
EXECUTABLES = $(patsubst $(TEST_DIR)/%.c, $(BIN_DIR)/%, $(SOURCES))

all: $(EXECUTABLES)

$(BIN_DIR)/%: $(OBJ_DIR)/%.o $(SRC_DIR)/data_structures.o
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c $(SRC_DIR)/data_structures.h
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC_DIR)/data_structures.o: $(SRC_DIR)/data_structures.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean

