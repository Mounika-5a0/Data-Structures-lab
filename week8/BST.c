#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct BST
{
	int data;
	struct BST *left, *right;
};
struct BST* root = NULL, *temp, *cur;
void create()
{
	temp = root;
	cur = (struct BST*) malloc(sizeof(struct BST));
	printf("enter data\n");
	scanf("%s", cur -> data);
	cur -> left = NULL;
	cur -> right = NULL;
	if(temp == NULL)
		root = cur;
	else
	{
		while(temp != NULL)
		{
			if((cur -> data) < (temp -> data))
			{
				if(temp -> left == NULL)
				{
					temp -> left = cur;
					return;
				}
				else
					temp = temp -> left;
			}
			else
			{
				if(temp -> right == NULL)
				{
					temp -> right = cur;
					return;
				}
					temp = temp -> right;
			}
		}
	}
}
void preorder(struct BST *temp)
{
	if(temp!=NULL)
	{
		printf("%d\n",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}
void postorder(struct BST *temp)
{
	if(temp != NULL)
	{
		postorder(temp -> left);
		postorder(temp -> right);
		printf("%d\n", temp -> data);
	}
}
void inorder(struct BST *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		printf("%d\n",temp->data);
		inorder(temp->right);
	}
}
int main()
{
	int ch;
	printf("menu options\n");
	printf("1 - create\n2 - preoreder\n3 - inorder\n4 - postorder\n5 - exit\n");
	while(1)
	{
		printf("enter your choice\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1 : create();
				break;
			case 2 : printf("preorder traversal\n");
			              preorder(root);
				break;
			case 3 : printf("Inorder traversal\n");
			              inorder(root);
				break;
			case 4 : printf("postorder traversal\n");
			              postorder(root);
				break;
			case 5 : exit(0);
				break;
			default : printf("invalid choice\n");
		}
	}
}