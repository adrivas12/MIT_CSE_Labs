#include<stdio.h>
#include<stdlib.h>
#include "tree.c"

int main()
{
	Node *tree=(Node *)malloc(sizeof(Node));
	createBT(&tree);
	printf("Inorder: ");
	inorder(tree);
	printf("\nPre order: ");
	preorder(tree);
	printf("\nPost Order: ");
	postorder(tree);
	return 0;
}