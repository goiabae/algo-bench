# Talvez no windows o compilador precise ser alterado para o MingW. Eu nao sei
CC := gcc
NAME := algo-bench
RM := rm -f

build: $(NAME).c timer.c
	mkdir -p bin
	$(CC) $(NAME).o timer.o -o bin/$(NAME)

$(NAME).c: src/timer.h $(NAME).c
	$(CC) -c src/$(NAME).c

timer.c: timer.c
	$(CC) -c src/timer.c

clean:
	$(RM) bin/$(NAME)
	$(RM) *.o
