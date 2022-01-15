#include <stdio.h>

int phase = 1;


void printArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
}


int getMax(int a[], int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];
	return max;
}

void countSort(int a[], int n, int pos)
{
	int op[n], p, val, i;
	int count[10] = { 0 };

	for (i = 0; i < n; i++)
		++count[(a[i] / pos) % 10];

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		p = (a[i] / pos) % 10;
		val = --count[p];
		op[val] = a[i];
	}

	printf("\n after %d phase :", phase);
	printArray(op, n);
	phase++;

	for (i = 0; i < n; i++)
		a[i] = op[i];

}

void radixSort(int a[], int n)
{
	int m = getMax(a, n);
	for (int pos = 1; m / pos > 0; pos *= 10)
		countSort(a, n, pos);
}





int main()
{
	int a[100], n, i;
	printf("\n Enter the number of items to be sorted: ");
	scanf("%d", &n);
	printf("\n Enter the items: ");
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	radixSort(a, n);
	printf("\nsorted sequence :");
	printArray(a, n);
}
