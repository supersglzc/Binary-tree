#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

int main(int argc, char ** argv){
	Node * root = NULL;
	int i = 0, j = 0, max = 1000;
	int input[max];
	char temp;
	int root_int;
	//printf("Please enter an integer value for the root: ");
	//scanf("%d\n", &root_int);
	//fflush(stdout); 
	printf("Now you can enter integer values to build the tree: \n");
	do{
		scanf("%d%c", &input[i], &temp);
		i ++;
	}while (temp != '\n');
	printf("The value we get from the input: ");
	for (j = 0; j < i; j ++){
		printf("%d ", input[j]);
	}
	printf("\n");
	root_int = input[0];
	printf("The root of the tree is: %d\n", root_int);
	
	for(int k = 0; k < i; k ++){
		root = insertion(root, input[k]);
	}
//	printf("The number of leaves is %d\n", num_leaves(root));
//	printf("The number of full nodes is %d\n", num_full_nodes(root));
	int command;
	printf("Enter command:\n1 to print the tree in increasing order\n2 to print the tree in decreasing order\n3 to insert a node\n4 to delete a node\n5 to get the number of leaves\n6 to get the number of full nodes\n7 to quit: ");
	scanf("%d", &command);
	while (command != 7){
		if (command == 1)
			print_sorted_increase(root);
			printf("\n");
		if (command == 2)
			print_sorted_decrease(root);
			printf("\n");
		if (command == 3){
			printf("Please enter the value you want to insert: ");
                        int insert;
                        scanf("%d", &insert);
                        root = insertion(root, insert);
                        printf("Inserted!\n");

		}
		if (command == 4){
			printf("Please enter the value you want to delete: ");
			int delete;
			scanf("%d", &delete);
			root = deletion(root, delete); 
			printf("Deleted!\n");
		}
		if (command == 5){
			printf("The number of leaves is %d\n", num_leaves(root));	
		}
		if (command == 6){
                        printf("The number of full nodes is %d\n", num_full_nodes(root));
                }
		printf("Enter command:\n1 to print the tree in increasing order\n2 to print the tree in decreasing order\n3 to insert a node\n4 to delete a node\n5 to get the number of leaves\n6 to get the number of full nodes\n7 to quit: ");
        	scanf("%d", &command);
	}
	free(root);	
}
