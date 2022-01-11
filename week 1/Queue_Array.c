#include<stdio.h>

#define SIZE 20

void enQueue(int);
int deQueue();
void display();

int queue[SIZE], front = -1, rear = -1;

int main()
{
   int value, choice;
   printf("\n Queue implementation using Arrays \n");
   
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
   if(rear == SIZE-1)
      printf("\nQueue is Full\n");
   else{
      if(front == -1)
	 front = 0;
      queue[++rear] = value;
      printf("\nInsertion is done successfully");
   }
}


int deQueue()
{
	int temp=0;
   if(front == rear)
      return temp;
   else{
      temp= queue[front++];
   if(front == rear)
	 front = rear = -1;
	 return temp;
   }
}


void display()
{
   if(rear == -1)
      printf("\nQueue is Empty\n");
   else{
      int i;
      printf("\nQueue elements are:\n");
      for(i=front; i<=rear; i++)
	  printf("%d\t",queue[i]);
   }
}

