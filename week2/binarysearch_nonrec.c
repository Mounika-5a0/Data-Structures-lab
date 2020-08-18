#include<stdio.h>
int binary_search(int first, int last, int a[50], int key)
{
	int mid, pos = -1;
	while(first <= last)
	{
		mid = (first +last) / 2;
		if ( a[mid] == key)
			return mid;
		else if (key < a[mid])
			last = mid - 1;
		else
			first = mid + 1;
	}
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
	pos = binary_search(0, n-1, a, key); 
	if(pos == -1)
		printf("Element is not present");
	else
		printf("Element is found at position %d", pos + 1);
}
	