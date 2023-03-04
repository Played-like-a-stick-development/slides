CC = g++
CFLAGS = -g -Wall
OPTIMIZATION_FLAGS = -O2
LIBS = -lncurses
SRC = main.cpp
EXEC = main

.PHONY: all
all: $(SRC)
	@echo "Build using Meson"
	@meson compile -C builddir
	@cp builddir/main main

.PHONY: setup
setup: $(SRC)
	@echo "Create Meson Project"
	@meson setup builddir

.PHONY: run
run: main
	@./main

.PHONY: make
make: $(EXEC)

.PHONY: make-optimized
make-optimized: CFLAGS += $(OPTIMIZATION_FLAGS)
make-optimized: $(EXEC)

$(EXEC): $(SRC)
	SDL2-CFLAGS := $(shell sdl2-config --cflags)
	SDL2-LIBS := $(shell sdl2-config --libs) -lSDL2_ttf
	@echo "CC $(SRC) > $(EXEC)"
	@$(CC) $(CFLAGS) $(SDL2-CFLAGS) $(SRC) -o $(EXEC) $(LIBS) $(SDL2-LIBS)
	@echo "Done"

.PHONY: clean
clean:
	@echo "Cleaning directory"
	@rm -rf $(EXEC) *:Zone.Identifier builddir/
	@echo "Done"
