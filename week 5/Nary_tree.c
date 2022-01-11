#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXCHILD 100

struct frequency
{
    int count;
};
struct node
{
    char str[100];
    struct node *child[100];
    struct frequency *freq;
};

struct word
{
    char str[100];
    int count;
    struct word *next;
};

struct node *root = NULL;
struct word *head = NULL, *tail = NULL;

struct node *createNode(char str[100])
{
    int i = 0;

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    strncpy(newNode->str, str, 100);

    for (i = 0; i < MAXCHILD; i++)
    {
        newNode->child[i] = NULL;
    }

    newNode->freq = NULL;

    return newNode;
}

struct node *insertCategory(char arr[100])
{
    int i;
    for (i = 0; i < MAXCHILD; i++)
    {
        if (NULL != root->child[i] && strcmp(root->child[i]->str, arr) == 0)
        {
            printf("\nCategory %s is present", arr);
            return root->child[i];
        }
        else if (NULL == root->child[i])
        {
            root->child[i] = createNode(arr);
            printf("\n%s is inserted as category", arr);
            return root->child[i];
        }
    }
    return NULL;
}

void insertGroupMem()
{
    char arr[100], arr1[100];
    printf("\nEnter group word: ");

    scanf(" %[^\n]s", arr);

    printf("Enter word category: ");
    scanf(" %[^\n]s", arr1);

    struct node *category = insertCategory(arr1);

    if (category != NULL)
    {
        int i;
        for (i = 0; i < MAXCHILD; i++)
        {

            if (category->child[i] != NULL && strcmp(category->child[i]->str, arr) == 0)
            {
                ++category->child[i]->freq->count;
                printf("\nFrequency of word %s is increased to %d", category->child[i]->str, category->child[i]->freq->count);
                return;
            }
            else if (category->child[i] == NULL)
            {
                category->child[i] = createNode(arr);
                struct frequency *newFreq = (struct frequency *)malloc(sizeof(struct frequency));
                newFreq->count = 1;
                category->child[i]->freq = newFreq;

                printf("\n%s is inserted into %s category", category->child[i]->str, arr1);
                return;
            }
        }
    }
}

void printRoot(struct node *root)
{
    if (root)
    {
        printf("\nNode :%s", root->str);
        int i;
        for (i = 0; i < MAXCHILD; i++)
        {
            printRoot(root->child[i]);
        }
    }
}

bool isLeaf(struct node *root)
{
    if (NULL != root && root->child[0] == NULL && (root->freq == NULL || root->freq->count == 1))
    {
        return true;
    }
    return false;
}

void displayLeafNodes(struct node *root)
{
    if (NULL != root)
    {
        if (isLeaf(root))
        {
            printf("  %s,", root->str);
            return;
        }
        int i = 0;
        for (i = 0; i < MAXCHILD; i++)
        {
            if (NULL != root->child[i])
            {
                displayLeafNodes(root->child[i]);
            }
        }
    }
}

void displayCategory()
{
    int i, j;
    printf("\nCategory \t Words:");
    for (i = 0; i < MAXCHILD; i++)
    {
        struct node *children = root->child[i];
        if (NULL != children)
        {
            printf("\n%s ::", children->str);
            for (j = 0; j < MAXCHILD; j++)
            {
                if (NULL != children->child[j])
                {
                    printf(",    %s", children->child[j]->str);
                }
            }
        }
    }
}

bool depthOfNode(struct node *root, int depth, char arr[100])
{
    if (root)
    {
        if (strcmp(root->str, arr) == 0)
        {
            printf("\nDepth of node %s is %d", arr, depth);
            return true;
        }
        int i, j;
        bool temp = false;
        for (i = 0; i < MAXCHILD; i++)
        {
            if (root->child[i])
            {
                temp = (temp || depthOfNode(root->child[i], depth + 1, arr));
            }
        }
        return temp;
    }
    return false;
}

bool degreeOfNode(char arr[100], struct node *root)
{
    bool temp = false;
    if (root)
    {
        if (strcmp(root->str, arr) == 0)
        {
            int count = 1, j;
            for (j = 0; j < MAXCHILD;)
            {
                if (NULL != root->child[j])
                {
                    j++;
                    count++;
                }
                else
                {
                    break;
                }
            }
            if (root->freq != NULL && root->freq->count > 1)
            {
                count++;
            }
            printf("\nDegree of node %s is %d", arr, count);
            return true;
        }

        int i, j;
        for (i = 0; i < MAXCHILD; i++)
        {
            struct node *rootChild = root->child[i];
            if (rootChild != NULL)
            {
                temp = temp || degreeOfNode(arr, rootChild);
            }
        }
    }
    return temp;
}

void getLeafNodes()
{
    int i, j;
    for (i = 0; i < MAXCHILD; i++)
    {
        struct node *children = root->child[i];
        if (NULL != children)
        {
            for (j = 0; j < MAXCHILD; j++)
            {
                if (NULL != children->child[j])
                {
                    struct word *newWord = (struct word *)malloc(sizeof(struct word));
                    strncpy(newWord->str, children->child[j]->str, 100);
                    newWord->count = children->child[j]->freq->count;
                    newWord->next=NULL;

                    // printf("\nNewWord %s Freq: %d",newWord->str,newWord->count);

                    if (head == NULL)
                    {
                        head = newWord;
                        tail = newWord;
                    }
                    else
                    {
                        tail->next = newWord;
                        tail = newWord;
                    }
                }
            }
        }
    }
}

void swap(struct word *a, struct word *b)
{
    char tempArr[100];
    int temp;
    temp = b->count;
    strncpy(tempArr, b->str, 100);
    strncpy(b->str, a->str, 100);
    strncpy(a->str, tempArr, 100);
    b->count = a->count;
    a->count = temp;
}

void displayWords()
{

    getLeafNodes();
    if (tail)
    {
        struct word *current = head, *index = NULL;
        int temp;

        while (current != NULL)
        {
            index = current->next;

            while (index != NULL)
            {
                if (current->count < index->count)
                {
                    swap(current, index);
                }

                index = index->next;
            }
            current = current->next;
        }

        current = head;
        printf("\nWords\t\tFrequency");
        while (current)
        {
            printf("\n%s\t\t%d", current->str, current->count);
            current = current->next;
        }
    }
    else
    {
        printf("\nTree is empty");
    }
}

void printUsage()
{
    printf("\n\nEnter options:\n1. To insert Category word\n2. To insert group member\n3. To display Leaf Nodes\n4. To display depth of Nodes\n5. To display degree of node\n6. To display words\n7. Display categories");
}

int main()
{
    root = createNode("WORDS");
    printf("\nRoot is created as WORDS");
    printUsage();
    while (1)
    {
        char arr[100];
        int choice;
        printf("\n\nEnter choice:");
        scanf("%d", &choice);
        if (choice == 1)
        {
            char arr[100];
            printf("\nEnter Category word to insert: ");
            scanf(" %[^\n]s", arr);
            insertCategory(arr);
        }
        else if (choice == 2)
        {
            insertGroupMem();
        }
        else if (choice == 3)
        {
            displayLeafNodes(root);
        }
        else if (choice == 4)
        {
            printf("\nEnter Word to find depth: ");
            char arr[100];
            scanf("%s", arr);
            bool isFound = depthOfNode(root, 0, arr);
            if (!isFound)
            {
                printf("\nNode %s is not present in Tree", arr);
            }
        }
        else if (choice == 5)
        {
            printf("\nEnter Word to find degree: ");
            char arr[100];
            scanf("%s", arr);
            bool isFound = degreeOfNode(arr, root);
            if (!isFound)
            {
                printf("\nNode %s is not present in Tree", arr);
            }
        }
        else if (choice == 6)
        {
            head = NULL;
            tail = NULL;
            displayWords();
        }
        else if (choice == 7)
        {
            displayCategory();
        }
        else
        {
            printf("\nEnter valid choice");
            printUsage();
        }
    }

    return 0;
}
