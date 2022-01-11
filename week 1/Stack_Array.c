#include <stdio.h>
#define SIZE 20

void push(int);
int pop();
void display();

int stack[SIZE], top = -1;

int main()
{
   int value, choice;
   printf("\n Stack implementation using Arrays \n");
   
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
   if(top == SIZE-1)
      printf("\nStack Overflow/\n");
   else{
      
      stack[++top] = value;
      printf("\nInsertion is done successfully");
   }
}



int pop()
{
	int temp=0;
   if(top == -1)
      return temp;
   else{
      temp=stack[top--];
      return temp;
      }
}


void display()
{
   if(top == -1)
      printf("\nStack is Empty\n");
   else{
      int i;
      printf("\nStack elements are:\n");
      for(i=top; i>=0; i--)
	 printf("%d\n",stack[i]);
   }
}


