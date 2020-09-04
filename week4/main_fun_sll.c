#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
};
struct node*head = NULL,*tail = NULL,*cur,*next,*prev;

void create()
{
	int n, i;
	printf("enter no. of nodes\n");
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		cur = (struct node *)malloc(sizeof(struct node));
		printf("enter current node data\n");
		scanf("%d",&(cur -> data));
		cur -> link = NULL;
		if(head == NULL)
		{
			head = tail = cur;
		}
		else
		{
			tail -> link = cur;
			tail = cur;
		}
	}
}

//insertion at begining
void insert_at_begin()
{
	cur = (struct node *)malloc(sizeof(struct node));
	scanf("%d", &(cur -> data));
	cur -> link = head;
	head = cur;
}

//insertion at end
void insert_at_end()
{
	cur = (struct node *)malloc(sizeof(struct node));
	printf("Enter data");
	scanf("%d", &(cur -> data));
	cur -> link = NULL;
	tail -> link = cur;
}

//insertion at given position
void insert_at_position()
{
	int pos, c = 1;
	cur = (struct node *)malloc(sizeof(struct node));
	scanf("%d", &(cur -> data));
	scanf("%d", &pos);
	next = head; 
	while( c < pos)
	{
		prev = next;
		next = next -> link;
		c++;
	}
	prev -> link = cur;
	cur -> link = next;
}

//insertion before a given node
void insert_before()
{
	int value;
	cur = (struct node *)malloc(sizeof(struct node));
	scanf("%d", &(cur -> data));
	next = head;
	printf("enter data to insert before which node");
	scanf("%d", &value);
	next = head;
	while(next -> data != value && next != NULL)
	{
		prev = next;
		next = next -> link;
	}
	prev -> link = cur;
	cur -> link = next;
} 

//insertion after the given node
void insert_after()
{
	int value;
	cur = (struct node *)malloc(sizeof(struct node));
	scanf("%d", &cur -> data);
	printf("enter after which we need to perform insertion\n");
	scanf("%d", &value);
	next = head;
	while(next -> data != value && next != NULL);
	{
		next = next -> link;
	}
	cur -> link = next -> link;
	next -> link = cur; 
} 

//deletion at begining
void delete_at_begin()
{
	cur = head;
	head = cur -> link;
	cur -> link  = NULL;
	printf("deleted element is %d \n", cur -> data);
	free(cur);
}

//deletion at end 
void delete_at_end()
{
	cur = head;
	while(cur -> link != tail)
	{
		cur = cur -> link;
	}
	cur -> link = NULL;
	next = tail;
	printf("deleted element is %d\n", next -> data);
}

//deletion at given position
void delete_at_pos()
{
	int pos, c = 1;
	printf("enter position of deletion\n");
	scanf("%d", &pos);
	next = head;
	while(c < pos)
	{
		prev = next; 
		next = next -> link;
		c++;
	}
	prev -> link = next -> link;
	printf("deleted element is %d\n", next -> data);
	next -> link = NULL;
	free(next);
}

//delete before given node
void delete_before()
{
	int value;
	printf("enter before which node we need to delete\n");
	scanf("%d",&value);
	next = head;
	while(next -> link -> data != value)
	{
		prev = next;
		next = next -> link;
	}
	prev -> link = next -> link;
	next -> link = NULL;
	printf("deleted element is %d\n", next -> data);
	free(next);
} 

//deletion after a given node
void delete_after()
{
	int value;
	scanf("%d", &value);
	next = head;
	while(next -> data != value)
	{
		prev = next;
		next = next -> link;
	}
	prev = next -> link;
	next -> link = prev -> link;
	printf("deleted data is %d\n", prev -> data);
	prev -> link = NULL;
	free(prev);
}

// sorting in single linked list
void bubble_sort_sll()
{
	struct node * p1, * p2;
	p1 = head;
	int c = 0, i, t;
	while(p1 != NULL)
	{
		c++;
		p1 =  p1 -> link;
	}
	for(i = 0; i < c; i++)
	{
		p2 = head;
		while(p2 -> link != NULL)
		{
			if(p2 -> data > p2 -> link -> data)
			{
				t = p2 -> data;
				p2 -> data = p2 -> link -> data;
				p2 -> link -> data = t;
			}
			p2 = p2 -> link;
		}
	
	}
}
 
//function to display in reverse
void reverse()
{
	if( head != NULL)
	{
		reverse(head -> link);
		printf("%d ->",head -> data);
	}
}

 
void display()
{
	if(head == NULL)
		printf("list is empty\n");
	else
	{
		next = head;
		while(next != NULL)
		{
			printf("%d\n",next -> data);
			next = next -> link;
		}
	}
}

//funtion to search elements
void search_for_element()
{
	int key, flag = 0, c = 0;
	printf("enter the value to be searched\n");
	scanf("%d",&key);
	next = head;
	while(next  != NULL)
	{
		if(next -> data == key)
		{
			flag = 1;
			break;
		}
		next = next -> link;
		c++;
	}
	if(flag == 1)
		printf("element is found at %d position\n", c);
	else
		printf("element is not found\n");
}


int main()
{
	int ch; 
	while(1)
	{
		printf("program for single linked list\n");
		printf("1 - create\n2 - insert at begin\n3 - insert at position\n4 - insert at end");
		printf("\n5 - insert before\n6 - insert after\n7 - delete at begin\n8 - delete at end");
		printf("\n9 - delete at position\n10 - delete before\n11 - delete after\n12 - traversal");
		printf("\n13 - display in reverse\n14 - search\n15 - sort\n16 - exit\n");
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
			case 12: display();
				break;
			case 16: exit(0);
		}
	}
}

 