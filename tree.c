#include "tree.h"

Node * insertion(Node * root, int key){
	if (!root){
		Node * buffer = malloc(sizeof(Node));
		buffer->left = NULL;
		buffer->right = NULL;
		buffer->key = key;
		return buffer;
	}else{
		if (key < root->key){
			root->left = insertion(root->left, key);
		}else if (key > root->key){
			root->right = insertion(root->right, key);
		}
	}
	return root;
}

void print_sorted_increase(Node * node){
	if (!node){
		return;
	}
	print_sorted_increase(node->left);
	printf("%d ", node->key);
	print_sorted_increase(node->right);
}

void print_sorted_decrease(Node * node){
        if (!node){
                return;
        }
        print_sorted_decrease(node->right);
        printf("%d ", node->key);
        print_sorted_decrease(node->left);
}

Node * deletion(Node * node, int key){
	if(!node){
		return node;
	}
	if (key < node->key){
		node->left = deletion(node->left, key);
	}else if (key > node->key){
		node->right = deletion(node->right, key);
	}else{
		if (!node->left){
			Node * buffer = node->right;
			free(node->right);
			return buffer;
		}else if(!node->right){
			Node * buffer = node->left;
			free(node->left);
			return buffer;
		}
		node->key = get_minimum(node->right);
		node->right = deletion(node->right, node->key);
	}
	return node;
}	

int get_minimum(Node * node){
	Node * buffer = node;
	while (buffer->left){
		buffer = buffer->left;
	}
	int minimum = buffer->key;
	return minimum;
}

Queue * create_Queue(int capacity){
	Queue * q = malloc(sizeof(Queue));
	q->capacity = capacity;
	q->front = 0;
	q->size = 0;
	q->rear = capacity - 1;
	q->array = malloc(capacity * sizeof(Node));
	return q;
}

void enqueue(Queue* q, Node * node) 
{ 
    if (q->size == q->capacity) 
        return; 
    q->rear = (q->rear + 1) % q->capacity; 
    q->array[q->rear] = node; 
    q->size ++; 
} 

Node * dequeue(Queue * q) 
{ 
    if (q->size == 0) 
        return NULL; 
    Node * node = q->array[q->front]; 
    q->front = (q->front + 1) % q->capacity; 
    q->size --; 
    return node; 
} 

int num_leaves(Node * root){
	if (!root)
		return 0;
	Queue * q = create_Queue(1000);
	int count = 0;
	enqueue(q, root);
	while (q->size != 0){
		Node * buffer = dequeue(q);
		if (buffer->left != NULL)
			enqueue(q, buffer->left);
		if (buffer->right != NULL)
                        enqueue(q, buffer->right);
		if ((buffer->left == NULL) && (buffer->right == NULL)){
			count ++;
		}
	}
	free(q->array);
	free(q);
	return count;
}

int num_full_nodes(Node * root){
        if (!root)
                return 0;
        Queue * q = create_Queue(1000);
        int count = 0;
        enqueue(q, root);
        while (q->size != 0){
                Node * buffer = dequeue(q);
                if (buffer->left != NULL)
                        enqueue(q, buffer->left);
                if (buffer->right != NULL)
                        enqueue(q, buffer->right);
                if ((buffer->left != NULL) && (buffer->right != NULL)){
                        count ++;
                }
        }
	free(q->array);
	free(q);
        return count;
}




