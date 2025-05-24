# Define paths
BIN_DIR = /bin

# List of all source files in the directory
SRC_FILES = $(wildcard *.c)

# Define object files for all .c files
OBJ_FILES = $(SRC_FILES:.c=.o)

# Default target (compile all .c files)
all: $(OBJ_FILES)

# Rule to compile .c files into .o files
$(BIN_DIR)/%.o: %.c
	@gcc -c $< -o $@

# Rule to create executables
$(BIN_DIR)/%: %.c
	@gcc $< -o $@

# Clean up object files and executables
clean:
	@rm -f $(BIN_DIR)/*

