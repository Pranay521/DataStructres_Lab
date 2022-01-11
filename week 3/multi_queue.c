#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
struct Node
{
    int front;
    int rear;
    int count;
};

struct Node multiQueue[5];
int n, k, arr[100000], next[100000], freeIndex = 0;

bool isFull()
{
    if (freeIndex == -1)
    {
        return true;
    }
    return false;
}

bool isEmpty(int queueNumber)
{
    if (multiQueue[queueNumber].front == -1)
    {
        return true;
    }
    return false;
}
void enqueue(int item, int qn)
{
    if (isFull())
    {
        printf("Queue Overflow");
        return;
    }
    if (qn < 1 || qn > 4)
    {
        printf("\nInvalid queueNumber\n");
        return;
    }

    int i = freeIndex;

    freeIndex = next[i];

    if (isEmpty(qn))
        multiQueue[qn].front = i;
    else
        next[multiQueue[qn].rear] = i;

    next[i] = -1;

    multiQueue[qn].rear = i;

    arr[i] = item;
    ++multiQueue[qn].count;
}

int dequeue(int qn)
{
    if (isEmpty(qn))
    {
        printf("Queue Underflow");
        return INT_MAX;
    }
    if (qn < 1 || qn > 4)
    {
        printf("\nInvalid queueNumber\n");
        return INT_MAX;
    }

    int i = multiQueue[qn].front;

    multiQueue[qn].front = next[i];

    next[i] = freeIndex;
    freeIndex = i;
    --multiQueue[qn].count;
    return arr[i];
}

void initialize()
{
    int i;
    for (i = 1; i <= 4; i++)
    {
        multiQueue[i].front = -1;
        multiQueue[i].rear = -1;
        multiQueue[i].count = 0;
    }
    freeIndex = 0;
    for (i = 0; i < n - 1; i++)
        next[i] = i + 1;

    next[n - 1] = -1;
}

void display()
{
    int i;
    for (i = 1; i <= 4; i++)
    {

        if (isEmpty(i))
        {
            printf("\nQueue %d is empty : ", i);
            continue;
        }
        printf("\nElements in Queue  Q%d: ", i);
        int front = multiQueue[i].front;
        do
        {
            printf(" %d", arr[front]);
            front = next[front];
            if (front != -1)
                printf(",");
        } while (front != -1);
    }
}
void insert(int item)
{
    int minQueue = 1, count = multiQueue[1].count, i;
    for (i = 1; i <= 4; i++)
    {
        if (count > multiQueue[i].count)
        {
            count = multiQueue[i].count;
            minQueue = i;
        }
    }

    enqueue(item, minQueue);
    printf("Inserting element %d in q%d:", item, minQueue);
}

void deleteQ()
{
    int maxQueue = 0, count = INT_MIN, i;
    for (i = 1; i <= 4; i++)
    {
        if (count < multiQueue[i].count)
        {
            count = multiQueue[i].count;
            maxQueue = i;
        }
    }
    if (maxQueue != 0)
    {
        int element = dequeue(maxQueue);
        if (element != INT_MAX)
            printf("\nDeleted element %d in q%d ", element, maxQueue);
    }
}

void displayChoice()
{
    printf("\nPlease enter: \n\tTo insert: 1 \n\tTo delete: 2 \n\tTo enqueue: 3 \n\tTo dequeue: 4 \n\tDisplay Queue: 5 \n\tExit: 6\n\n");
}
void runDynamic()
{
    displayChoice();
    while (1)
    {
        int choice;
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int item;
            printf("\nEnter element to insert: ");
            scanf("%d", &item);
            insert(item);
        }
        else if (choice == 2)
        {
            deleteQ();
        }
        else if (choice == 3)
        {
            int queueNumber, element;
            printf("\nEnter queueNumber: and element to enqueue: ");
            scanf("%d %d", &queueNumber, &element);
            enqueue(element, queueNumber);
        }
        else if (choice == 4)
        {
            int queueNumber;
            printf("\nEnter queueNumber to dequeue: ");
            scanf("%d", &queueNumber);
            int element = dequeue(queueNumber);
            if (element != INT_MAX)
                printf("\nDeleted element %d in q%d ", element, queueNumber);
        }
        else if (choice == 5)
        {
            display();
        }
        else if (choice == 6)
        {
            return;
        }
        else
        {
            printf("\nPlease enter valid choice ");
            displayChoice();
        }
    }
}
int main()
{

    k = 4;
    n = 100000;
    int choice;
    initialize();
    enqueue(11,1);
    enqueue(12,1);
    enqueue(13,1);
    enqueue(14,1);
    enqueue(15,1);
    
    enqueue(21,2);
    enqueue(22,2);
    enqueue(23,2);
    
    enqueue(31,3);
    enqueue(32,3);
    
    enqueue(41,4);
    enqueue(42,4);
    enqueue(43,4);
    enqueue(44,4);
    enqueue(45,4);
    enqueue(46,4);
    
     display();
     printf("\n\n");
    runDynamic();
    return 0;
}
