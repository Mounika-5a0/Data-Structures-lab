#include<stdio.h>
int linear_search(int a[50], int n, int key)
{
	static int i;
	if(a[i] == key)
		return i;
	else if(i < n)
	{
		i++;
		linear_search(a, n, key);
	}
	else
		return -1;
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
	