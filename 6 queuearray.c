                                    // queue with array//

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

void insert();
void del();
void display();

int i,front=-1,q[MAX],rear=-1;

void insert()                // for insert data //
{
 if(rear==MAX-1)
 {
   printf("queue overflow\n");
 }

 if(front==-1)
 {
     front=0;
     rear=rear+1;
     printf("enter data :");
     scanf("%d",&q[rear]);
 }
}

void del()                        // for delete data //
{
  if(front==-1 || front==rear+1)
  {
    printf("queue underflow\n");
  }
  else
  {
    printf("delete data is %d ",q[front]);
    front=front+1;
  }
}

void display()                       // for display data//
{
 if(front==-1 || front==rear+1)
 {
  printf("list is empty\n");
 }

 else
 {
   for(i=front;i<=rear;i++)
   {
     printf("%d\t",q[i]);
   }
 }
}

int menu()
{
 int ch;
 printf("\n1 for insert");
 printf("\n2 for delete");
 printf("\n3 for display");
 printf("\n4 for exit");
 printf("\nenter choice: ");
 scanf("%d",&ch);
 return(ch);
}

void main()
{

      printf("\t\t\t\t\t\tQueue with array\n");
  while(1)
  {
    switch(menu())
    {
     case 1:
           insert();
           break;

     case 2:
            del();
            break;

            case 3:
               display();
               break;
            case 4:
                 exit(0);

               default:
                printf("wrong input");
    }
  }
}

