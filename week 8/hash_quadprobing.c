#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define TABLE_SIZE 10

int h[TABLE_SIZE];
float count=0;


void init_array()
{
    int i;
    for (i = 0; i <TABLE_SIZE ; i++) 
    {
	  h[i]=INT_MIN;
	
    }
}

void insert()
{
	

 int key,index,i,flag=0,hkey;
 printf("\nenter a value to insert into hash table\n");
 scanf("%d",&key);
 hkey=key%TABLE_SIZE;
 for(i=0;i<TABLE_SIZE;i++)
    {

     index=(hkey+i*i)%TABLE_SIZE;
     
     if(h[index] == key)
     {
     	printf("\n This key is already present in hash table, hence updating it's value \n");
        h[index]=key;
    
         break;
     }

     if(h[index] == INT_MIN)
     {
     	count++;
        h[index]=key;
    
         break;
     }

    }

    if(i == TABLE_SIZE)

     printf("\nelement cannot be inserted\n");
}


void search()
{

 int key,index,i,flag=0,hkey;
 printf("\nenter search element\n");
 scanf("%d",&key);
 hkey=key%TABLE_SIZE;
 for(i=0;i<TABLE_SIZE; i++)
 {
    index=(hkey+i*i)%TABLE_SIZE;
    if(h[index]==key)
    {
      printf("value is found at index %d",index);
      break;
    }
    else if (h[index] == INT_MAX || h[index] != INT_MIN)
	  continue;
  }
  if(i == TABLE_SIZE)
    printf("\n value is not found\n");
}


void display()
{

  int i;

  printf("\nelements in the hash table are \n");

  for(i=0;i< TABLE_SIZE; i++)

  printf("\nat index %d \t value =  %d",i,h[i]);

}


void loadFactor()
{
    float f= TABLE_SIZE;
	printf("\nthe load factor of hash table is:%f",count/f);
}

void delete()
{
	

 int key,i,hkey,index;
 printf("\nenter a value to be deleted from hash table\n");
 scanf("%d",&key);
 hkey=key%TABLE_SIZE;
 for(i=0;i<TABLE_SIZE;i++)
    {
       index=(hkey+i*i)%TABLE_SIZE;
       
       if(h[index] == INT_MIN)
     {
     	printf("Element not found in hash table\n");
     	break;
	 }
	 
       

	 if(h[index]==key)
	 {
	 	h[index]=INT_MAX;
	 	count--;
	 	printf("Element deleted\n\n");
	 	break;
	 }
	 
    }

    if(i == TABLE_SIZE)
       printf("Element not found in hash table\n");
}



int main()
{
	printf("\n Hash Table Size here is :: %d",TABLE_SIZE);
	init_array();
    int opt,i;
    while(1)
    {
        printf("\nPress 1. Insert\t 2. Delete \t3. Search \t4. Loadfactor \t5. Display \t6. exit \n");
        scanf("%d",&opt);
        if(opt==1)
        {
        	insert();
		}
		else if(opt==2)
		{
			delete();
		}
		else if(opt==3)
		{
			search();
		}
		else if(opt==4)
		{
			loadFactor();
		}
		else if(opt==5)
		{
			display();
		}
		
		else if(opt==6)
		{
			exit(0);
		}
		else
		{
			printf("\nenter valid option");
		}
    }
    return 0;
}

