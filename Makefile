# Compiler and compiler flags
CC = gcc
CFLAGS =-Wall -I./include -fpic -g -fbounds-check
LIBS=-lm -lncurses

# Directories
SRC_DIR = source
BUILD_DIR = build

# List of source files and object files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

# Executable name
TARGET = ascii-renderer

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJ_FILES)
	$(CC) -o $@ $^ $(LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)
