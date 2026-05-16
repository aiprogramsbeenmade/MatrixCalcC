TARGET = MatrixCalcC
CC = gcc
CFLAGS = -Wall -Iinclude -Ilib

SRCS = src/algebra.c src/menusystem.c src/menumatrix.c main.c
OBJ = $(SRCS:.c=.o)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

all:
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f src/*.o $(TARGET)