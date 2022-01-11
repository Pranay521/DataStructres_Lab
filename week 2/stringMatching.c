#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node
{
    char str[3][10];
    struct Node *next;
};

struct Node *head = NULL, *tail = NULL;

void insertNode(char a[10], char b[10], char c[10])
{
    struct Node *tempNode = (struct Node *)malloc(sizeof(struct Node));
    strncpy(tempNode->str[0], a, 10);
    strncpy(tempNode->str[1], b, 10);
    strncpy(tempNode->str[2], c, 10);
    tempNode->next = NULL;

    if (head == NULL)
    {
        head = tempNode;
        tail = tempNode;
    }
    else
    {
        tail->next = tempNode;
        tail = tempNode;
        tail->next = head;
    }
}

void replace()
{
    char tempArr[10];
    strncpy(tempArr, tail->str[0], 10);
    strncpy(tail->str[0], head->str[0], 10);
    strncpy(head->str[0], tempArr, 10);
}

void displayList()
{

    if (head == NULL)
    {
        return;
    }
    struct Node *start = head;
    bool isMatch = true;

    do
    {
        printf("%s, %s, %s \n", start->str[0], start->str[1], start->str[2]);

        if (strncmp(start->str[2], start->next->str[0], 10))
        {
            isMatch = false;
        }
        start = start->next;
    } while (start != tail->next);

    if (isMatch)
    {
        printf("\nString Matching\n");
    }
    else
    {
        printf("\nString not Matching\n");
    }
}

void traverselist()
{
    if (head == NULL)
    {
        return;
    }
    struct Node *start = head;
    do
    {
        printf("%s\n ", start->str[1]);
        start = start->next;
    } while (start != tail->next);
}

int main()
{
    insertNode("blue", "red", "green");
    insertNode("green", "black", "yellow");
    insertNode("yellow", "white", "orange");
    insertNode("orange", "grey", "violet");
    insertNode("violet", "brown", "blue");

    printf("\nbefore replacing List : \n");
    
    displayList();
    printf("\n\n");
    printf("\nSecond-string values of a linked list\n");
    traverselist();
    printf("\n\n");
    replace();
    printf("After replacing: \n\n");
    displayList();
    return 0;
}
