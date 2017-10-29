CC=gcc
CFLAGS=-Wall
OBJ=./linkedlists/linkedlist.o ./queue/queue.o ./arrays/vector/vector.o

make: $(OBJ)
	$(MAKE) -C arrays/vector
	$(MAKE) -C linkedlists
	$(MAKE) -C queue
	$(CC) $(CFLAGS) $(OBJ) -o main.o main.c -I.
