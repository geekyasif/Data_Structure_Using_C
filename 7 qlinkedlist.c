                                    // queue with linked list //

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

void insert();
void del();
void display();

struct node
{
      int data;
      struct node*next;
};

struct node*front=NULL,*rear=NULL;

struct node* create()
{
   struct node*n;
   n=(struct node*)malloc(sizeof(struct node));
   return(n);
}

void insert()                // for insert data //
{

    struct node*m,*ptr;
    m=create();
    printf("enter data : ");
    scanf("%d",&m->data);
    m->next=NULL;

 if(rear==NULL && front==NULL)   // insertion of first data//
 {
   front=m;
   rear=m;
 }
 else                           // insertion after first data//
 {   ptr=rear;
    ptr->next=m;
    rear=m;
 }
}

void del()                        // for delete data //
{
    struct node *ptr;
  if(front==NULL)
  {
    printf("queue underflow\n");
  }
  else
  {
      ptr=front;
      printf("delted data is %d",ptr->data);
      front=ptr->next;
      free(ptr);
  }
}

void display()                       // for display data//
{
     struct node*ptr;
 if(front==NULL)
 {
  printf("list is empty\n");
 }

 else
 {
   ptr=front;
   while(ptr!=NULL)
   {
    printf("%d ",ptr->data);
    ptr=ptr->next;
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

