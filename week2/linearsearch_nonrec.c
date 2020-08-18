#include<stdio.h>
int linear_search(int a[50], int n, int key)
{
	int i, pos = -1;
	for(i = 0; i < n; i++)
	{
		if(a[i] == key)
		{
			pos = i;
			break;
		}
	}
	return pos;
}
int main()
{
	int a[50];
	int n, key, i, pos;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &key);
	pos = linear_search(a, n, key); 
	if(pos == -1)
		printf("Element is not present");
	else
		printf("Element is found at position %d", pos + 1);
}
	