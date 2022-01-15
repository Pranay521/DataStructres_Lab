#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int q[MAX], f = 0, r = -1, n, adj[MAX][MAX], visited[MAX];

void enqueue(int v)
{
	if (r == MAX - 1)
		printf("\nQueue Overflow, Unable to insert");
	else
		q[++r] = v;

}

int dequeue()
{
	if (f == (r + 1))
		printf("\nQueue Underflow, Unable to delete");

	return q[f++];

}

int isEmpty()
{
	if (f > r)
		return 1;
	return 0;
}

void createGraph()
{
	printf("\n enter the number of nodes in the graph:");
	scanf("%d", &n);
	int i, j;

	for (i = 0; i < n; i++)
	{
		printf("Enter the adjacency list for node %d:", i + 1);
		for (j = 0; j < n; j++)
			scanf("%d", &adj[i][j]);
	}

	printf("\nThe adjacency matrix of the graph is:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", adj[i][j]);
		}

		printf("\n");
	}
}

void displayChoice()
{
	printf("\nPlease enter: \n\tTo Create Graph: 1 \n\tTo BFS Traversal: 2 \n\tTo DFS Traversal: 3 \n\tTo Exit: 4\n\n");
}

void BFS(int s)
{
	printf("%d", s);
	visited[s] = 1;
	enqueue(s);
	while (!isEmpty())
	{
		s = dequeue();
		for (int i = 0; i < n; i++)
		{
			if (adj[s][i] == 1 && visited[i] == 0)
			{
				printf("%d ", i);
				visited[i] = 1;
				enqueue(i);
			}
		}
	}

	printf("\n");

}

void DFS(int s)
{
	printf("%d ", s);
	visited[s] = 1;
	for (int i = 0; i < n; i++)
	{
		if (adj[s][i] == 1 && visited[i] == 0)
			DFS(i);
	}
}

int main()
{
	displayChoice();
	while (1)
	{
		int choice;
		printf("\nEnter choice: ");
		scanf("%d", &choice);
		if (choice == 1)
		{
			createGraph();
		}
		else if (choice == 2)
		{
			for (int i = 0; i < n; i++)
				visited[i] = 0;
			int v;
			printf("Enter Start Vertex for BFS: \n");
			scanf("%d", &v);
			printf("Following is Breadth First Traversal (starting from vertex %d):", v);
			BFS(v);

		}
		else if (choice == 3)
		{
			for (int i = 0; i < n; i++)
				visited[i] = 0;
			int v;
			printf("Enter Start Vertex for DFS: \n");
			scanf("%d", &v);
			printf("Following is Depth First Traversal (starting from vertex %d):", v);
			DFS(v);
		}
		else if (choice == 4)
		{
			exit(1);
		}
		else
		{
			printf("\nPlease enter valid choice ");
			displayChoice();
		}
	}

	return 0;
}
