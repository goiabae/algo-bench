# Talvez no windows o compilador precise ser alterado para o MingW. Eu nao sei
CC := gcc
NAME := algo-bench

all: src/$(NAME)

src/$(NAME):
	mkdir -p bin
	$(CC) -o bin/$(NAME) src/$(NAME).c

clean:
	rm -f bin/$(NAME)
