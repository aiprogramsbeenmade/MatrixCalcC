TARGET = main
CC = gcc
CFLAGS = -Wall -Iinclude

SRCS = *.c

all:
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)