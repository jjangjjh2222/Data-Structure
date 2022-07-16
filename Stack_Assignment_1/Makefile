CC=gcc
CFLAGS=-Wall

all: main.o stack_array_2021062579.o stack_linkedlist_2021062579.o
	$(CC) $(CFLAGS) -o main main.o stack_array_2021062579.o stack_linkedlist_2021062579.o

main.o: main.c stack_array.h stack_linkedlist.h
	$(CC) $(CFLAGS) -c main.c

stack_array_2021062579.o: stack_array_2021062579.c stack_array.h
	$(CC) $(CFLAGS) -c stack_array_2021062579.c

stack_linkedlist_2021062579.o: stack_linkedlist_2021062579.c stack_linkedlist.h
	$(CC) $(CFLAGS) -c stack_linkedlist_2021062579.c

clean:
	rm -rf *.o
	rm -rf main
