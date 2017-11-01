CC=gcc
CFLAGS=-Wall
OBJ=./linkedlists/linkedlist.o ./queue/queue.o ./queue/fixedqueue/fixed_queue.o ./arrays/vector/vector.o

make: $(OBJ)
	$(MAKE) -C arrays/vector
	$(MAKE) -C linkedlists
	$(MAKE) -C queue
	$(MAKE) -C queue/fixedqueue
	$(CC) $(CFLAGS) $(OBJ) -o main.o main.c -I.
