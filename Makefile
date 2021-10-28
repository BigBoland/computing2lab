CC = gcc
CFLAGS = -Wall --std=c99 -g
OBJECTS = main.o my_string.o

hello: $(OBJECTS)
	$(CC) $(CFLAGS) -o string_driver $(OBJECTS)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o
clean:
	rm string_driver $(OBJECTS)

