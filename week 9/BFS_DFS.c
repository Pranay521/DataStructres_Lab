#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define MAX 100

int n;
int adj[MAX][MAX];
int visited[MAX];
void create_graph();
void init(int arr[MAX][MAX]);
void printAdjMatrix(int adj[MAX][MAX]);
void BF_Traversal();
void BFS(int v);
void DF_Traversal();
void DFS(int v);

int queue[MAX], front = -1, rear = -1;
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();

void insert_queue(int vertex)
{
	if (rear == MAX - 1)
		printf("Queue Overflow\n");
	else
	{
		if (front == -1)
			front = 0;
		rear = rear + 1;
		queue[rear] = vertex;
	}
}

int delete_queue()
{
	int delete_item;

	if (front == -1 || front > rear)
	{
		printf("Queue Underflow\n");
		exit(1);
	}

	delete_item = queue[front];
	front = front + 1;
	return delete_item;
}

int isEmpty_queue()
{
	if (front == -1 || front > rear)
		return 1;
	else
		return 0;
}

// Initialize the matrix to zero

void init(int arr[MAX][MAX])
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			arr[i][j] = 0;
}

void create_graph()
{
	int count, max_edge, origin, destin;
	max_edge = n *(n - 1);
	for (count = 1; count <= max_edge; count++)
	{
		printf("Enter the end points of the edge %d(-1 -1 to quit) : ", count);
		scanf("%d %d", &origin, &destin);
		if ((origin == -1) && (destin == -1))
			break;
		if (origin >= n || destin >= n || origin < 0 || destin < 0)
		{
			printf("Invalid edge!\n");
			count--;
		}
		else
		{
			adj[origin][destin] = 1;
			adj[destin][origin] = 1;
		}
	}
}

void printAdjMatrix(int adj[MAX][MAX])
{
	// Traverse the adj[][]
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// Print the value at adj[i][j]
			printf("%d ", adj[i][j]);
		}

		printf("\n");
	}
}

void BF_Traversal()
{
	int v;
	for (v = 0; v < n; v++)
		visited[v] = 0;
	printf("Enter Start Vertex for BFS: \n");
	scanf("%d", &v);
	printf("Following is Breadth First Traversal (starting from vertex %d):", v);
	BFS(v);
}

void BFS(int v)
{
	int i;
	printf("%d ", v);
	visited[v] = 1;
	insert_queue(v);

	while (!isEmpty_queue())
	{
		v = delete_queue();
		for (i = 0; i < n; i++)
		{
			if (adj[v][i] == 1 && visited[i] == 0)
			{
				printf("%d ", i);
				visited[i] = 1;
				insert_queue(i);

			}
		}
	}

	printf("\n");
}

void DF_Traversal()
{
	int v;
	for (v = 0; v < n; v++)
		visited[v] = 0;
	printf("Enter Start Vertex for DFS: \n");
	scanf("%d", &v);
	printf("Following is Depth First Traversal (starting from vertex %d):", v);
	DFS(v);
}

void DFS(int v)
{
	int j;

	if (visited[v] == 0)
	{
		printf("%d ", v);
		visited[v] = 1;

		for (j = 0; j < n; j++)
		{
			if (adj[v][j] == 1 && visited[j] == 0)
				DFS(j);
		}
	}
}

void displayChoice()
{
	printf("\nPlease enter: \n\tTo Create Graph: 1 \n\tTo Print Adjacencymatrix: 2 \n\tTo BFS Traversal: 3 \n\tTo DFS Traversal: 4 \n\tTo Exit: 5\n\n");
}

int main()
{
	printf("Enter number of vertices : ");
	scanf("%d", &n);
	init(adj);
	displayChoice();
	while (1)
	{
		int choice;
		printf("\nEnter choice: ");
		scanf("%d", &choice);
		if (choice == 1)
		{
			create_graph();
		}
		else if (choice == 2)
		{
			printAdjMatrix(adj);
		}
		else if (choice == 3)
		{
			BF_Traversal();
		}
		else if (choice == 4)
		{
			DF_Traversal();
		}
		else if (choice == 5)
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
