// Radix Sort in C Programming
#include <stdio.h>

int p = 1;
void printArray(int array[], int size);
int getMax(int array[], int n);
void countingSort(int array[], int size, int place);
void radixsort(int array[], int size);


int main()
{
	int array[100], n, i;

	printf("Enter the number of items to be sorted: ");
	scanf("%d", &n);
	printf("Enter items: ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}

	radixsort(array, n);
	printf("\nsorted sequence :");
	printArray(array, n);
}


void printArray(int array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d  ", array[i]);
	}

	printf("\n");
}

// Function to get the largest element from an array
int getMax(int array[], int n)
{
	int max = array[0];
	for (int i = 1; i < n; i++)
		if (array[i] > max)
			max = array[i];
	return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int array[], int size, int place)
{
	int output[size + 1];

	int count[10];

	for (int i = 0; i < 10; ++i)
		count[i] = 0;

	// Calculate count of elements
	for (int i = 0; i < size; i++)
		count[(array[i] / place) % 10]++;

	// Calculate cumulative count
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Place the elements in sorted order
	for (int i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}

	printf("\n after %d phase :", p);
	printArray(output, size);
	p++;

	for (int i = 0; i < size; i++)
		array[i] = output[i];
}

// function to implement radix sort
void radixsort(int array[], int size)
{
	// Get maximum element
	int max = getMax(array, size);

	// Apply counting sort to sort elements based on place value.
	for (int place = 1; max / place > 0; place *= 10)
		countingSort(array, size, place);
}



