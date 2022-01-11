#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

void printUsage()
{
    printf("\nUsage : Please enter \nTo insert node at head : 1 \nTo insert node at tail : 2\nTo Display list : 3 \nExit: 4 \n\n");
}

int getElement()
{
    printf("Please enter element: ");
    int value;
    scanf("%d", &value);
    if (value == 0 || value == 1)
    {
        return value;
    }
    else
    {
        printf("Please enter data value in 0/1\n\n");
    }
    return 2;
}

void insertNodeAtHead(int data)
{

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        
        newNode->next = head;
        head = newNode;
       
        
    }
    
    
}

void insertNodeAtTail(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    
    
}

void displayList()
{
    if (head == NULL)
    {
        printf("List is empty please insert nodes\n\n");
        return;
    }
    struct node *start = head;
    int total = 0;
    printf(" List : ");
    while (start != NULL)
    {
        int value = start->data;
        printf("%d", value);
        total = (total * 2) + value;
        start = start->next;
        if (start != NULL)
        {
            printf(" -> ");
        }
    }
    printf("\nTotal value : %d \n\n", total);
}

int main()
{
    printUsage();
    while (1)
    {
        int option;
        printf("Enter choice : ");
        scanf("%d", &option);
        if (option == 1)
        {
            int data = getElement();
            if (data == 1 || data == 0)
            {
                insertNodeAtHead(data);
            }
            
            
        }
        else if (option == 2)
        {
            int data = getElement();
            if (data == 1 || data == 0)
            {
                insertNodeAtTail(data);
            }
            
            
        }
        else if (option == 3)
        {
            displayList();
            
        }
        else if (option == 4)
        {
            break;
        }
        else
        {
            printUsage();
        
        }
    }
    return 0;
}
