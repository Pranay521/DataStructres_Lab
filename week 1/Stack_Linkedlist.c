#include<stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node *next;
}*top = NULL;



void push(int);
int pop();
void display();

int main()
{
   int value, choice;
   printf("\n Stack implementation using Linkedlists \n");
   
   do
 {
 printf("\n\n Basic Stack Operations are....\n");
 printf("\n 1. PUSH\n 2. POP\n 3. DISPLAY\n 4. EXIT\n");
 printf("\nEnter your choice : ");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
 {
 printf("Enter the value to be insert: ");
		 scanf("%d",&value);
		 push(value);
		 break;
 }
 case 2:
 {
 int x=pop();
 if(x==0)
 printf("\nStack Underflow\n");
 else
 printf("Popped element from the Stack is:%d",x);
 
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



void push(int value)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   
   if(!newNode)
   {
   	printf ("\nheap is running out of space\n");
   	exit(0);
   }
   
   newNode->data = value;
   if(top == NULL)
      newNode->next = NULL;
   else
      newNode->next = top;
   top = newNode;
   printf("\nInsertion is done Successfully\n");
}




int pop()
{
   int tmp=0;
   if(top == NULL)
      return tmp;
   else
   {
      struct Node *temp = top;
      tmp=temp->data;
      top = temp->next;
      free(temp);
      return tmp;
   }
}




void display()
{
   if(top == NULL)
      printf("Stack is Empty\n");
   else{
   	
   	 printf("\nStack elements are:\n");
      struct Node *temp = top;
      while(temp->next != NULL)
	  {
	    printf("%d\n",temp->data);
	    temp = temp -> next;
      }
      printf("%d",temp->data);
   }
}


