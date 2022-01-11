#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <math.h>

void merge (int A[], int p, int q, int r);
void mergesort (int A[], int p, int r);

void
swap (int *arr, int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int
main ()
{
  int p = 0;
  printf ("\nPerformance metrics: \n\n");
  printf ("Input size\t\tRandom\t\tSorted\t\t  Almost sorted");
  for (p = 4; p <= 7; p++)
    {
      int count = pow (10, p);
      int *arr = (int *) malloc (count * sizeof (int));
      srand (time (0));
      clock_t c1, c2, c3, c4, c5, c6, c7, c8;
      double runtime;
      printf ("\n%d\t\t", count);
      int i;
      for (i = 0; i < count; i++)
	{
	  int ele;
	  arr[i] = (rand () * rand ()) % 1000000001;
	}
      c1 = clock ();

      mergesort (arr, 0, count - 1);
      c2 = clock ();

      runtime = (double) (c2 - c1) / (double) CLOCKS_PER_SEC;
      // printf("runtime :%f is",runtime);
      printf ("%f\t\t", runtime);
      c3 = clock ();

      mergesort (arr, 0, count - 1);
      c4 = clock ();
      runtime = (double) (c4 - c3) / (double) CLOCKS_PER_SEC;
      // printf("runtime :%f is",runtime);
      printf ("%f\t\t", runtime);
      int s, k, p, q;
      s = (1 / 100) * count;
      int x = 0;

      for (k = 0; k < s; k++)
	{
	  srand (time (0));
	  p = x + rand () % count;

	  swap (arr, k, p);
	}

      c5 = clock ();

      mergesort (arr, 0, count - 1);
      c6 = clock ();
      runtime = (double) (c6 - c5) / (double) CLOCKS_PER_SEC;
      printf ("%f\t\t", runtime);
    }
}

void
merge (int A[], int p, int q, int r)
{
  int n1 = q - p + 1;
  int n2 = r - q;
  int *L = (int *) malloc ((n1 + 1) * sizeof (int));
  int *R = (int *) malloc ((n2 + 1) * sizeof (int));
  int i, j, k;

  for (i = 0; i < n1; i++)
    {
      L[i] = A[p + i];
    }

  for (j = 0; j < n2; j++)
    {
      R[j] = A[q + 1 + j];
    }

  L[n1] = INT_MAX;
  R[n2] = INT_MAX;

  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2)
    {
      if (L[i] <= R[j])
	{
	  A[k] = L[i];
	  i++;
	}
      else
	{
	  A[k] = R[j];
	  j++;
	}
      k++;
    }

  while (i < n1)
    {
      A[k] = L[i];
      i++;
      k++;
    }

  while (j < n2)
    {
      A[k] = R[j];
      j++;
      k++;
    }
}

void
mergesort (int A[], int p, int r)
{
  if (p < r)
    {
      int q = (p + r) / 2;
      mergesort (A, p, q);
      mergesort (A, q + 1, r);
      merge (A, p, q, r);
    }
}

