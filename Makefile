CC = g++
CFLAGS = -g -Wall
RELEASE_FLAGS = -O2
LIBS = -lncurses
SRC = main.cpp
EXEC = main

.PHONY: all
all: $(EXEC)

.PHONY: release
release: CFLAGS += $(RELEASE_FLAGS)
release: $(EXEC)

$(EXEC): $(SRC)
	@echo "CC $(SRC) > $(EXEC)"
	@$(CC) $(CFLAGS) $(SRC) -o $(EXEC) $(LIBS)
	@echo "Done"

.PHONY: clean
clean:
	@echo "Cleaning directory"
	@rm -rf $(EXEC)
	@echo "Done"
