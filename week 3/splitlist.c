#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *head = NULL, *secondHead = NULL;

void insertAtEnd(int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->info = data;
	temp->next = NULL;

	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		struct node *last = head;
		while (last->next)
		{
			last = last->next;
		}
		last->next = temp;
	}
}

void display(struct node *head)
{
	if (head == NULL)
		return;
	struct node *last = head->next;
	printf("%d ", head->info);
	while (last != head)
	{
		printf("--> %d ", last->info);
		last = last->next;
	}
}

void circularList()
{
	struct node *temp = head;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = head;
	printf("\nCircular Linked List is created Successfully\n");
	return;
}

void splitList(int x)
{
	if (x == 1)
	{
		printf("\nCannot split one node");
		return;
	}
	int mid = x / 2;
	if (x % 2 == 1)
	{
		mid++;
	}

	struct node *current = head;
	struct node *midNode = NULL;

	int i = 1;
	while (current->next != head)
	{
		if (i == mid)
		{
			midNode = current;
		}
		i++;
		current = current->next;
	}
	secondHead = midNode->next;
	current->next = secondHead;
	midNode->next = head;

	return;
}

int main()
{
	int count, i;
	printf("\nEnter the number of elements:: ");
	scanf("%d", &count);

	for (i = 0; i < count; i++)
	{
		int data;
		printf("Enter the element:: ");
		scanf("%d", &data);
		insertAtEnd(data);
	}
	circularList();
	printf("\nCircular LinkedList created is :");
	display(head);
	splitList(count);
	printf("\n\nAfter Splitting");
	printf("\nFirst List: ");
	display(head);
	printf("\nSecond List: ");
	display(secondHead);
	return 0;
}
