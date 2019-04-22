CC = gcc
CFLAGS = -Wall -std=c99

all: tree_test

tree.o: tree.c tree.h 
	$(CC) $(CFLAGS) -c tree.c

tree_test.o: tree_test.c tree.o tree.h
	$(CC) $(CFLAGS) -c tree_test.c
	
tree_test: tree_test.o 
	$(CC) $(CFLAGS) -o tree_test tree.o tree_test.o 

clean:
	rm *.o tree_test
