#include<stdio.h>
#include<stdlib.h>
struct node 
{
	float data;
	struct node * prev;
	struct node * next;
};
struct node * head = NULL, *tail = NULL, *cur, *t1, *t2; 


//function to create dll 
void create()
{
	int n, i;
	printf("enter no. of nodes\n");
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		cur = (struct node *)malloc(sizeof(struct node));
		printf("enter current node data\n");
		scanf("%f", &(cur -> data));
		cur -> prev = NULL;
		cur -> next = NULL;
		if(head == NULL)
			head = tail = cur;
		else
		{
			tail -> next = cur;
			cur -> prev = tail;
			tail = cur;
		}
	}
}

//insertion at begining
void insert_at_begin()
{
	cur = (struct node *)malloc(sizeof(struct node));
	printf("enter current node data\n");
	scanf("%f",&(cur -> data));
	cur -> prev = NULL;
	cur -> next = head;
	head -> prev = cur;
	head = cur;
}

//insertion at end
void insert_at_end()
{
	cur = (struct node *)malloc(sizeof(struct node));
	printf("enter current node data\n");
	scanf("%f",&(cur -> data));
	cur -> next= NULL;
	cur -> prev = tail;
	tail -> next = cur;
	tail = cur;
}

//insertion at given position
void insert_at_position()
{
	int c = 1, pos;
	cur = (struct node *)malloc(sizeof(struct node));
	printf("enter current node data\n");
	scanf("%f",&(cur -> data));
	printf("enter the position of insertion\n");
	scanf("%d",&pos);
	t1 = head;
	while(c < pos && t1 != NULL)
	{
		t2 = t1;
		t1 = t1 -> next;
		c++;
	}
	t2 -> next = cur;
	cur -> prev = t2;
	cur -> next = t1;
	t1 -> prev = cur;
}

//insert before given node
void insert_before()
{
	float value;
	cur = (struct node *)malloc(sizeof(struct node));
	printf("enter current node data\n");
	scanf("%f",&(cur -> data));
	printf("enter the data before which we need to insert\n");
	scanf("%f",&value);
	t1 = head;
	while(t1 != NULL && t1 -> data != value)
	{
		t2 = t1;
		t1 = t1 -> next;
	}
	t2 -> next = cur;
	cur -> prev = t2;
	cur -> next = t1;
	t1 -> prev = cur;
}


//insert after given node
void insert_after()
{
	float value;
	cur = (struct node *)malloc(sizeof(struct node));
	printf("enter current node data\n");
	scanf("%f",&(cur -> data));
	printf("enter the data after which we need to insert\n");
	scanf("%f",&value);
	t1 = head;
	while(t1 -> data != value && t1 != NULL)
		t1 = t1 -> next;
	cur -> next = t1 -> next;
	t1 -> next -> prev = cur;
	t1 -> next = cur;
	cur -> prev = t1;
}

//delete at beginig
void delete_at_begin()
{
	cur = head;
	head = head -> next;
	head -> prev = NULL;
	cur -> next = NULL;
	printf("deleted element %f\n", cur -> data);
	free(cur);
}
//delete at end
void delete_at_end()
{
	cur = tail;
	tail = tail -> prev;
	tail -> next = NULL;
	cur -> prev = NULL;
	printf("deleted element %f\n",cur -> data);
	free(cur);
} 
//delete at position
void delete_at_pos()
{
	int pos, c = 1;
	printf("enter position of deletion\n");
	scanf("%d", &pos);
	t1 = head;
	while( c < pos && t1 != NULL)
	{
		t2 = t1;
		t1 = t1 -> next;
		c++;
	}
	t2 -> next = t1 -> next;
	t1 -> next -> prev = t2;
	printf("deleted data id %f\n", t1 -> data);
	free(t1);
}


//delete before node
void delete_before()
{
	float value;
	printf("enter data before which we need to delete\n");
	scanf("%f",&value);
	t1 = head;
	while(t1 -> next -> data != value && t1 -> next != NULL)
	{
		t2 = t1;
		t1 = t1 -> next;
	}
	t2 -> next = t1 -> next;
	t1 -> next -> prev = t2;
	printf("deleted element %f\n",t1 -> data);
	free(t1);
}
//delete after node
void delete_after()
{
	float value;
	printf("enter data after which node we need to delete\n");
	scanf("%f",&value);
	t1 = head;
	while(t1 -> data != value && t1 != NULL)
		t1 = t1 -> next;
	t2 = t1 -> next;
	t1 -> next = t2 -> next;
	t2 -> next -> prev = t1;
	printf("deleted element %f", t2 -> data);
	free(t2);
}

//to display in forward direction
void display_forward()
{
	if(head == NULL)
		printf("dll is empty\n");
	else
	{
		cur = head;
		printf("elements of dll are\n");
		while(cur != NULL)
		{
			printf("%f <->\n ",cur -> data);
			cur = cur -> next;
		}
	}
}


//to display in reverse order
void display_reverse()
{
	if(head == NULL)
		printf("dll is empty\n");
	else
	{
		cur = tail;
		printf("elements of dll in reverse are\n");
		while(cur != NULL)
		{
			printf("%f <-> \n", cur -> data);
			cur = cur -> prev;
		}
	}
}

// searching elements
void search()
{
	int c = 1, flag = 0;
	float value;
	printf("enter the value to search\n");
	scanf("%f",&value);
	t1 = head;
	while( t1 != NULL)
	{
		if(t1 -> data == value)
		{
			flag = 1;
			break;
		}
		t1 = t1 -> next;
		c++;
	}
	if(flag == 1)
		printf("element present at %d positon\n",c);
	else
		printf("element is not found\n");
}

 
// sorting in double linked list
void sort()
{
	struct node * p1, * p2, *last = NULL;
	p1 = head;
	int c = 0, i, t;
	while(p1 -> next  != NULL)
	{
		c++;
		p1 =  p1 -> next;
	}
	for(i = 0; i < c; i++)
	{
		p2 = head;
		while(p2 -> next != NULL)
		{
			if(p2 -> data > p2-> next -> data)
			{
				t = p2 -> data;
				p2 -> data = p2 -> next -> data;
				p2 -> next -> data = t;
			}
			p2 = p2 -> next;
		}
	
	}
}
	
int main()
{
	int ch;
	while(1)
	{
		
		printf("program for double linked list\n");
		printf("1 - create\n2 - insert at begin\n3 - insert at position\n4 - insert at end");
		printf("\n5 - insert before\n6 - insert after\n7 - delete at begin\n8 - delete at end");
		printf("\n9 - delete at position\n10 - delete before\n11 - delete after\n12 - display");
		printf("\n13 - display in reverse\n14 - sort\n15 - search\n16 - exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();
				break;
			case 2: insert_at_begin();
				break;
			case 3: insert_at_position();
				break;
			case 4: insert_at_end();
				break;
			case 5: insert_before();
				break;
			case 6: insert_after();
				break;
			case 7: delete_at_begin();
				break;
			case 8: delete_at_end();
				break;
			case 9: delete_at_pos();
				break;
			case 10: delete_before();
				break;
			case 11: delete_after();
				break;
			case 12: display_forward();
				break;
			case 13: display_reverse();
				break;
			case 14: sort();
				break;
			case 15: search();
				break;
			case 16: exit(0);
		}
	}
}

 
	



