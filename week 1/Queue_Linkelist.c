#include<stdio.h>
#include<stdlib.h>

struct Node
{
   int data;
   struct Node *next;
}*front = NULL,*rear = NULL;

void enQueue(int);
int deQueue();
void display();


int main()
{
   int value, choice;
   printf("\n Queue implementation using Linkedlists \n");
   
   do
 {
 printf("\n\n Basic Queue Operations are....\n");
 printf("\n 1. ENQUEUE\n 2. DEQUEUE\n 3. DISPLAY\n 4. EXIT\n");
 printf("\nEnter your choice : ");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
 {
 printf("Enter the value to be insert: ");
		 scanf("%d",&value);
		 enQueue(value);
		 break;
 }
 case 2:
 {
 int x=deQueue();
 if(x==0)
 printf("\n Queue is empty\n");
 else
 printf("Dequeued element from the Queue is:%d",x);
  break;
 }
 case 3:
 {
 display();
 break;
 }
 case 4:
 {
 break;
 }
 default:
 {
 printf ("\nInvalid Choice\n");
 }}}
 while(choice!=4);
 return 0;
}


void enQueue(int value)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   
   if(newNode==NULL)
   {
   	printf ("\nheap is running out of space\n");
   	exit(0);
   }
   
   newNode->data = value;
   newNode -> next = NULL;
   if(front == NULL)
      front = rear = newNode;
   else
   {
      rear -> next = newNode;
      rear = newNode;
   }
   printf("\nInsertion is done Successfully\n");
}


int deQueue()
{
	int tmp=0;
   if(front == NULL)
      return tmp;
   else{
      struct Node *temp = front;
      front = front -> next;
      tmp=temp->data;
      free(temp);
      return tmp;
   }
}


void display()
{
   if(front == NULL)
      printf("\nQueue is Empty\n");
   else{
      struct Node *temp = front;
      while(temp->next != NULL)
	  {
	 printf("%d\t",temp->data);
	 temp = temp -> next;
      }
      printf("%d\n",temp->data);
   }
}
