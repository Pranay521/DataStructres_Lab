#include <stdio.h>
#include <stdlib.h>
int n=0;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void minHeapify (int *arr, int n, int i)
{
  int smallest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && arr[l] < arr[smallest])
    smallest = l;

  if (r < n && arr[r] < arr[smallest])
    smallest = r;

  if (smallest != i)
    {
      swap (&arr[i], &arr[smallest]);
      minHeapify (arr, n, smallest);
    }
}




void printHeap(int arr[], int n)
{
    int i;
    printf("Array representation of Heap is:\n");
      for (i = 0; i < n; ++i)
           printf("%d\t",arr[i]);
           printf("\n");
           return;
}

void delete(int arr[], int num)
{
  int i;
  for (i = 0; i < n; i++)
  {
    if (num == arr[i])
      break;
  }
  if(i==n)
  {
  	printf("element is not found\n");
  	return;
  }
  
  swap(&arr[i], &arr[n - 1]);
  n -= 1;
  for (i = n / 2 - 1; i >= 0; i--)
  {
    heapify(arr, n, i);
  }
  
  return;
}


void minDelete(int arr[], int num)
{
  int i;
  for (i = 0; i < n; i++)
  {
    if (num == arr[i])
      break;
  }
  if(i==n)
  {
  	printf("element is not found\n");
  	return;
  }
  
  swap(&arr[i], &arr[n - 1]);
  n -= 1;
  for (i = n / 2 - 1; i >= 0; i--)
  {
    minHeapify(arr, n, i);
  }
  
  return;
}


void insert(int arr[], int newNum)
{
  if (n == 0)
  {
    arr[0] = newNum;
    n += 1;
  }
  else
  {
    arr[n] = newNum;
    n += 1;
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
    {
      heapify(arr, n, i);
    }
  }
  return;
}

void minInsert(int arr[], int newNum)
{
  if (n == 0)
  {
    arr[0] = newNum;
    n += 1;
  }
  else
  {
    arr[n] = newNum;
    n += 1;
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
    {
      minHeapify(arr, n, i);
    }
  }
  return;
}

void buildHeap(int arr[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
	{
        heapify(arr, n, i);
    }
    return;
}

void minBuildHeap(int arr[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
	{
        minHeapify(arr, n, i);
    }
    return;
}


void heapSort(int *arr, int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (i = n - 1; i >= 0; i--)
    {

        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }
    
    return;
}

void minHeapSort(int *arr, int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    for (i = n - 1; i >= 0; i--)
    {

        swap(&arr[0], &arr[i]);

        minHeapify(arr, i, 0);
    }
    
    return;
}


int main()
{
	int choice;
	int arr[100];
	
    
    while(1)
    {
	 printf("\nPress 1. MAX_HEAPIFY \t 2. MIN_HEAPIFY  \n\n");
	 scanf("%d",&choice);
    if(choice==1)
    {
    	while(1)
    	{
    		int opt;
    		printf("\nPress 1. Build_Heap \t 2. Insert \t3. Delete \t4. Sort \t5. display \t6. exit \n");
    		scanf("%d",&opt);
    	if(opt==1)
        {
        	int k,q;
        	printf("Enter number of elements: ");
        	scanf("%d",&k);
        	printf("\nEnter elements: ");
        	for(q=n;q<n+k;q++)
        	{
        	   scanf("%d", &arr[q]);	
			}
			n=n+k;
        	buildHeap(arr,n);
		}
		else if(opt==2)
		{
			int key;
			printf("\nenter a value to insert into hash table\n");
            scanf("%d",&key);
			insert(arr,key);
		}
		else if(opt==3)
		{
			int key;
			printf("\nenter a value to be deleted from hash table\n");
            scanf("%d",&key);
            delete(arr,key);
		}
		else if(opt==4)
		{
			heapSort(arr, n);
		}
		else if(opt==5)
		{
			printHeap(arr,n);
		}
		
		else if(opt==6)
		{
			break;
		}
		else
		{
			printf("\nenter valid option");
		}

    		
		}
    	
    }
	else if(choice==2)
	{
	   while(1)
    	{
    		int opt;
    		printf("\nPress 1. Build_Heap \t 2. Insert \t3. Delete \t4. Sort \t5. display \t6. exit \n");
    		scanf("%d",&opt);
    	if(opt==1)
        {
        	int k,q;
        	printf("Enter number of elements: ");
        	scanf("%d",&k);
        	printf("\nEnter elements: ");
        	for(q=n;q<n+k;q++)
        	{
        	   scanf("%d", &arr[q]);	
			}
			n=n+k;
        	minBuildHeap(arr,n);
		}
		else if(opt==2)
		{
			int key;
			printf("\nenter a value to insert into hash table\n");
            scanf("%d",&key);
			minInsert(arr,key);
		}
		else if(opt==3)
		{
			int key;
			printf("\nenter a value to be deleted from hash table\n");
            scanf("%d",&key);
            minDelete(arr,key);
		}
		else if(opt==4)
		{
			minHeapSort(arr, n);
		}
		else if(opt==5)
		{
			printHeap(arr,n);
		}
		
		else if(opt==6)
		{
			break;
		}
		else
		{
			printf("\nenter valid option");
		}

    		
		}
 	
	}
    else
	{
		printf("enter valid choice\n");
    } 
    
    }
    
    return 0;   
}
