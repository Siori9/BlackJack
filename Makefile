CC = gcc
CFLAGS = -W -Wall -Wpedantic -g 
SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)

exe : $(OBJS)
	$(CC) -o $@ $^ -lm -lncursesw
%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< -lm -lncursesw
clean :
	@rm *.o