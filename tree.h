#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int key;
	struct node * left;
	struct node * right;
}Node;

Node * insertion(Node * root, int key);
void print_sorted_increase(Node * node);
void print_sorted_decrease(Node * node);
Node * deletion(Node * node, int key);
int get_minimum(Node * node);

typedef struct queue{
	int front, size, rear;
	int capacity;
	Node ** array;
}Queue;

Queue * create_Queue(int capacity);
void enqueue(Queue * q, Node * node);
Node * dequeue(Queue * q);
int num_leaves(Node * root);
int num_full_nodes(Node * root);
