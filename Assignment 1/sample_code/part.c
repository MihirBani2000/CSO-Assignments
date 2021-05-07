/*
** PROBLEM STATEMENT
**Partition an array (as in quick sort).
**Use first element of array as a pivot. 
**[ void partition(int *array, int noelements) ]
*/

#include <stdio.h>
extern void partition(int *array, int n);

int main()
{
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	partition(&a[0], n);
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}
