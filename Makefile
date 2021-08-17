# Talvez no windows o compilador precise ser alterado para o MingW. Eu nao sei
CC := gcc
NAME := algo-bench
RM := rm -f

build: $(NAME).o timer.o
	mkdir -p bin
	$(CC) $(NAME).o timer.o -o bin/$(NAME)

$(NAME).o: src/timer.h src/$(NAME).c
	$(CC) -c src/$(NAME).c

timer.o: src/timer.c
	$(CC) -c src/timer.c

clean:
	$(RM) bin/$(NAME)
	$(RM) *.o
