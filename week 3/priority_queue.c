#include <stdio.h>
#include <string.h>
#include <limits.h>

struct Node
{
    char name[50];
    int score;
};

struct Node pr[100000];
int size = -1, front = -1, n = 100000;

void enqueue(char name[], int score)
{
    size++;
    if (size >= n)
    {
        printf("\nQueue overflow declared size is 100000\n");
        return;
    }
     if (front == -1)
    {
        front = 0;
    }
    int position = size;
    int i;
    for (i = front; i < size; i++)
    {
        if (score > pr[i].score)
        {
            position = i;
            break;
        }
    }
    int j;
    for (j = size; j > position; j--)
    {
        pr[j] = pr[j - 1];
    }
    pr[position].score = score;
    strncpy(pr[position].name, name, 50);
    printf("\nItem inserted : %s --- %d", pr[position].name, pr[position].score);
   
}

void dequeue()
{
    if (front == -1 || front > size)
    {
        printf("\nQueue underflow");
        return;
    }
    printf("\nItem getting deleted: %s \t\t %d", pr[front].name, pr[front].score);
    front++;
}

void displayQueue()
{
    if (front == -1 || front > size)
    {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\n\nDisplay of queue: \nName \t\t Score");
    int i;
    for (i = front; i <= size; i++)
    {
        printf("\n%s \t\t %d", pr[i].name, pr[i].score);
    }
}

void runStatic()
{
    enqueue("ABC", 700);
    enqueue("CDE", 800);
    enqueue("FGH", 750);
    enqueue("IJK", 800);

    displayQueue();
    dequeue();
    enqueue("LMN", 780);

    dequeue();

    displayQueue();
}
void displayChoice()
{
    printf("\nPlease enter: \nTo insert: 1 \nTo delete: 2 \nTo show queue: 3 \nExit: 4");
}
void runDynamic()
{
    displayChoice();
    while (1)
    {
        int choice;
        printf("\nPlease enter choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int score;
            char name[50];
            printf("\nPlease enter name and score: ");
            scanf("%s %d", name, &score);
            enqueue(name, score);
        }
        else if (choice == 2)
        {
            dequeue();
        }
        else if (choice == 3)
        {
            displayQueue();
        }
        else if (choice == 4)
        {
            return;
        }
        else
        {
            printf("\nPlease enter valid choice:");
            displayChoice();
        }
    }
}

int main()
{
	
	
    int choice;
    printf("\nPlease enter 1 for static input, 2 for dynamic input: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        runStatic();
    }
    else if (choice == 2)
    {
        runDynamic();
    }
    else
    {
        printf("\nIncorrect choice entered");
    }
    return 0;
}
