#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
} node;

node *create()
{
	node *newnode;
	newnode = (node *)malloc(sizeof(node));
	
	if (newnode == 0)
	{
		printf("Memory Allocation Failed1\n");
		exit(1);
	}
	
	int x;
	printf("Enter the Data : ");
	scanf("%d", &x);
	
	if (x == -1)
		return 0;
		
	newnode -> data = x;
	
	printf("Left Child of %d : ", x);
	newnode -> left = create();
	
	printf("Right Child of %d : ", x);
	newnode -> right = create();
	
	return newnode;
}

void preorder(node *root)
{
	if (root == 0)
		return;
	
	printf("%d\t", root -> data);
	preorder(root -> left);
	preorder(root -> right);
}

void inorder(node *root)
{
	if (root == 0)
		return;
		
	inorder(root -> left);
	printf("%d\t", root -> data);
	inorder(root -> right);
}

void postorder(node *root)
{
	if (root == 0)
		return;
		
	postorder(root -> left);
	postorder(root -> right);
	printf("%d\t", root -> data);
}

int main()
{
	node *root;
	root = create();
	
	printf("\nPreorder : ");
	preorder(root);
	
	printf("\nInorder : ");
	inorder(root);
	
	printf("\nPostorder : ");
	postorder(root);
	
	return 0;
}
