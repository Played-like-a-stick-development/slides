CC = g++
CFLAGS = -g -Wall
LIBS = -lncurses
SRC = main.cpp
EXEC = main
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))

.PHONY: all
all: $(EXEC)

$(EXEC): $(OBJ)
	@echo "LD $(OBJ) $(LIBS) > $(EXEC)"
	@$(CC) $(OBJ) -o $(EXEC) $(LIBS)
	@echo "Done"

$(OBJ): $(OBJ_DIR)/%.o: %.cpp
	@echo "CC $< > $@"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

.PHONY: clean
clean:
	@echo "Cleaning directory"
	@rm -rf $(EXEC) $(OBJ_DIR)
	@echo "Done"
