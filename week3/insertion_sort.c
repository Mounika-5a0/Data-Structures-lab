#include<stdio.h>
void insertion_sort(int a[50], int n)
{
	int i, j, t;
	for(i = 1; i < n; i++)
	{
		t = a[i];
		j = i;
		while ((j > 0) && (a[j - 1] > t))
		{
			a[j] = a[j - 1];
			j = j -1;
		}
		a[j] = t;
	}
}

	int main()
{
	int n, a[50], i;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	insertion_sort(a, n);
	printf("Elements after sorting\n");
	for(i = 0; i < n; i++)
		printf("%d\t", a[i]);
}