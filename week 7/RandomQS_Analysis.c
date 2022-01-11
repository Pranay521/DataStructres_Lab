#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <math.h>

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int *arr, int low, int high, int pivot)
{
    int i = low - 1, j = high + 1;
    while (1)
    {
        do
        {
            i++;
        } while (i <= high && arr[i] < arr[pivot]);

        do
        {
            j--;
        } while (j >= low && arr[j] > arr[pivot]);

        if (i >= j)
            return j;
        swap(arr, i, j);
    }
}

int partitioning(int *arr, int low, int high)
{
    srand(time(NULL));
    int pivot = low + rand() % (high - low);
    swap(arr, low, pivot);
    return partition(arr, low, high, low);
}

void quicksort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partitioning(arr, low, high);
        quicksort(arr, low, pi);
        quicksort(arr, pi + 1, high);
    }
}

int main()
{
    int p = 0;
    printf("\nPerformance metrics: \n\n");
    printf("Input size\t\tRandom\t\tSorted\t\t  Almost sorted");
    for (p = 4; p <= 7; p++)
    {
        int count = pow(10, p);
    printf("\n%d\t\t",count);
    int *arr = (int *)malloc(count * sizeof(int));
   
    for (int i = 0; i < count; i++)
    {
        arr[i]=rand()%10000000000;
    }
   srand(time(0));
    clock_t c1, c2, c3, c4, c5, c6, c7, c8;
    double runtime;

    int i;
    for (i = 0; i < count; i++)
    {
        int ele;
        arr[i] = rand() % 1000000000;
    }
    c1 = clock();
    
    quicksort(arr,0, count - 1);
    c2 = clock();
   
    runtime = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    printf("%f\t\t",runtime);
   
    c3 = clock();
   
    quicksort(arr,0, count - 1);
    c4 = clock();
   
    runtime = (double)(c4 - c3) / (double)CLOCKS_PER_SEC;
    printf("%f\t\t", runtime);
    int s, k, p, q;
    s = (1 / 100) * count;
    int x = 0;

    for (k = 0; k < s; k++)
    {
        srand(time(0));
        p = x + rand() % count;

        swap(arr,k, p);
    }

    c5 = clock();
   
    quicksort(arr,0, count - 1);
    c6 = clock();
 
    runtime = (double)(c6 - c5) / (double)CLOCKS_PER_SEC;
    printf("%f\t\t", runtime);
    }
    return 0;
}
