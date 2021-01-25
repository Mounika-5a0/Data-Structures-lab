#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node * link;
};
struct node * top = NULL, *cur, *next, *prev;

void push()
{
	cur = (struct node *)malloc(sizeof(struct node));
	printf("enter current node data\n");
	scanf("%d", &(cur -> data));
	cur -> link = top;
	top = cur;
}

void pop()
{
	cur = top;
	top = cur -> link;
	cur -> link  = NULL;
	printf("deleted element is %d \n", cur -> data);
	free(cur);
}

void display()
{
	if(top == NULL)
		printf("stack is underflow\n");
	else
	{
		next = top;
		while(next != NULL)
		{
			printf("%d\n",next -> data);
			next = next -> link;
		}
	}
}

void peek()
{
	printf("The top most element of stack is %d\n",top -> data);
}
int main()
{
	int ch;
	while(1)
	{
		printf("programs for stack\n");
		printf("1 - push\n2 - pop\n3 - display\n4 - peek\n5 - exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		printf("--------------------\n");
		switch(ch)
		{
			case 1: push();
				break;
			case 2: pop();
				break;	
			case 3: display();
				break;	
			case 4: peek();
				break;	
			case 5: exit(0);
				break;
		}
	}
}		