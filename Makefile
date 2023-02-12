CC = g++
CFLAGS = -g -Wall
OPTIMIZATION_FLAGS = -O2
LIBS = -lncurses
SRC = main.cpp
EXEC = main
SDL2-CFLAGS := $(shell sdl2-config --cflags)
SDL2-LIBS := $(shell sdl2-config --libs) -lSDL2_ttf

.PHONY: all
all: $(EXEC)

.PHONY: optimized
optimized: CFLAGS += $(OPTIMIZATION_FLAGS)
optimized: $(EXEC)

$(EXEC): $(SRC)
	@echo "CC $(SRC) > $(EXEC)"
	@$(CC) $(CFLAGS) $(SDL2-CFLAGS) $(SRC) -o $(EXEC) $(LIBS) $(SDL2-LIBS)
	@echo "Done"

.PHONY: clean
clean:
	@echo "Cleaning directory"
	@rm -rf $(EXEC) *:Zone.Identifier
	@echo "Done"
