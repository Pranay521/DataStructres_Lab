#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct List
{
    struct Node *node;
    struct List *next;
};

struct Node *root = NULL;
struct List *head = NULL, *tail = NULL;

void insertList(int element)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->left = NULL;
    newNode->right = NULL;

    struct List *listNode = (struct List *)malloc(sizeof(struct List));
    listNode->node = newNode;
    listNode->next = NULL;

    if (root == NULL)
    {
        head = listNode;
        tail = listNode;
        root = newNode;
    }
    else
    {
        while (head->node && head->node->left && head->node->right)
        {
            head = head->next;
        }
        if (head->node->left == NULL)
        {
            head->node->left = newNode;
        }
        else if (head->node->right == NULL)
        {
            head->node->right = newNode;
        }
        tail->next = listNode;
        tail = listNode;
    }
}

void printInorder(struct Node *root)
{
    if (root)
    {
        printInorder(root->left);
        printf(" %d", root->data);
        printInorder(root->right);
    }
}

void printPreorder(struct Node *root)
{
    if (root)
    {
        printf(" %d", root->data);
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

void printPostorder(struct Node *root)
{
    if (root)
    {
        printPostorder(root->left);
        printPostorder(root->right);
        printf(" %d", root->data);
    }
}

int max(int a, int b)
{
    if (a >= b)
        return a;
    return b;
}

int FindHeight(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(FindHeight(root->left), FindHeight(root->right));
}

void PrintSpace(int n)
{
	int i;
	
    for (i = 0; i < n; ++i)
        printf(" ");
}

void displayTree(struct Node *root, int level)
{
    if (!root)
        return;
    displayTree(root->right, level + 1);
    PrintSpace(level * 6);
    printf("%d \n", root->data);
    displayTree(root->left, level + 1);
}
int main()
{
    int n, i;
    printf("\nEnter number of elements: ");
    scanf("%d", &n);

    printf("\nEnter elements: ");
    for (i = 0; i < n; i++)
    {
        int element;
        scanf("%d", &element);
        insertList(element);
    }

    int height = FindHeight(root);
    printf("\nHeight of the tree: %d", height);
    printf("\nInorder elements: ");
    printInorder(root);
    printf("\nPreorder elements: ");
    printPreorder(root);
    printf("\nPostorder elements: ");
    printPostorder(root);
    printf("\nTree Display: \n\n");
    displayTree(root, 0);
    return 0;
}
