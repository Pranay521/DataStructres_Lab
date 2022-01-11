#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

bool isFound = false;

void printUsage()
{
    printf("\nEnter choice \nTo insert: 1\nTo delete: 2\nTo Print level Order elements: 3\nTo Print elements of Specific level : 4\nTo Print Inorder elements : 5\nTo Print Preorder elements : 6\nTo Print Postorder elements: 7\nTo Print sum of elements in Left Subtree : 8\nTo Display Tree : 9\nTo exit: 0\n\n\n");
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

struct Node *minValueNode(struct Node *root)
{
    while (root->left)
    {
        root = root->left;
    }
    return root;
}

struct Node* newNode(int key)
{
	struct Node* node = (struct Node*)
						malloc(sizeof(struct Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; 
	return(node);
}


struct Node *rightRotate(struct Node *y)
{
	struct Node *x = y->left;
	struct Node *T2 = x->right;

	
	x->right = y;
	y->left = T2;

	
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	
	return x;
}


struct Node *leftRotate(struct Node *x)
{
	struct Node *y = x->right;
	struct Node *T2 = y->left;


	y->left = x;
	x->right = T2;

	
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	
	return y;
}


int getBalance(struct Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

struct Node* insert(struct Node* node, int key)
{
	
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else
		return node;

	
	node->height = 1 + max(height(node->left),
						height(node->right));

	
	int balance = getBalance(node);

	
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	
	return node;
}


struct Node *deleteNode(struct Node *root, int key) 
{
 
  if (root == NULL)
    return root;

  if (key < root->key)
    root->left = deleteNode(root->left, key);

  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else 
  {
  	isFound = true;
            if (root->left == NULL)
            {
                struct Node *temp = root->right;
                free(root);
                return temp;
            }
            if (root->right == NULL)
            {
                struct Node *temp = root->left;
                free(root);
                return temp;
            }

	         else
	        {
      struct Node *temp = minValueNode(root->right);

      root->key = temp->key;

      root->right = deleteNode(root->right, temp->key);
    }
  }

  if (root == NULL)
    return root;

  
  root->height = 1 + max(height(root->left),height(root->right));

  int balance = getBalance(root);
  if (balance > 1 && getBalance(root->left) >= 0)
    return rightRotate(root);

  if (balance > 1 && getBalance(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  if (balance < -1 && getBalance(root->right) <= 0)
    return leftRotate(root);

  if (balance < -1 && getBalance(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}








void printInorder(struct Node *root)
{
    if (root)
    {
        printInorder(root->left);
        printf(" %d", root->key);
        printInorder(root->right);
    }
}

void printPreorder(struct Node *root)
{
    if (root)
    {
        printf(" %d", root->key);
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
        printf(" %d", root->key);
    }
}

void printLevelNodes(struct Node *root, int level)
{
    if (level == 0 || root == NULL)
    {
        return;
    }
    if (level == 1)
    {
        printf(" %d", root->key);
    }
    else
    {
        printLevelNodes(root->left, level - 1);
        printLevelNodes(root->right, level - 1);
    }
}

void levelOrderTraverse(struct Node *root)
{
    int h = height(root);
    int l;
    for (l = 1; l <= h; l++)
    {
        printLevelNodes(root, l);
    }
}

int sumOfLeftSubtree(struct Node* root)
{
    if (root == NULL)
        return 0;
    return (root->key + sumOfLeftSubtree(root->left) + sumOfLeftSubtree(root->right));
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
    printf("%d \n", root->key);
    displayTree(root->left, level + 1);
}





int main()
{
	struct Node *root = NULL;
    printUsage();
    while (1)
    {

        int choice;
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("\nEnter element to insert: ");
            int element;
            scanf("%d", &element);
            root = insert(root,element);
        }
        else if (choice == 2)
        {
            printf("\nEnter element to delete: ");
            int element;
            scanf("%d", &element);
            root=deleteNode(root,element);
            if (isFound)
            {
                printf("\nElement is found and deleted");
            }
            else
            {
                printf("\nElement is not found");	
			}
            isFound = false;
        }
        else if (choice == 3)
        {
            printf("\nLevel order elements: ");
            levelOrderTraverse(root);
        }
        
        else if (choice == 4)
        {
        	int level;
        	printf("\nenter the level number: ");
        	scanf("%d",&level);
            printf("\n Specific Level order elements: ");
            printLevelNodes(root,level);
        }
        else if (choice == 5)
        {
            printf("\nInorder elements: ");
            printInorder(root);
        }
        else if (choice == 6)
        {
            printf("\nPreorder elements: ");
            printPreorder(root);
        }
        
        else if (choice == 7)
        {
            printf("\nPostorder elements: ");
            printPostorder(root);
        }
        
        else if (choice == 8)
        {
            int sum = sumOfLeftSubtree(root->left);
            printf("\nSum of all nodes in the Left Subtree: %d", sum);
        }
        
        else if (choice == 9)
        {
            printf("\nTree Display: \n\n\n\n\n");
            displayTree(root, 0);
        }
        
        else if (choice == 0)
        {
            exit(0);
        }
        else
        {
            printf("\nPlease enter valid choice: ");
            printUsage();
        }
    }
}
