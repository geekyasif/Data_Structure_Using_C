                               // stack program with linked list//

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void push();
void pop();
void display();

struct node{             // node data//
     int data;
     struct node*next;
};

struct node*top=NULL;

struct node*createnode()         // node creation//
{
  struct node*t;
  t=(struct node*)malloc(sizeof(struct node));
  return(t);
}

void push()           // insertion of data//
{
  struct node*n;

  n=createnode();
  printf("enter data : ");
  scanf("%d",&n->data);

  if(top==NULL)          //insertion at begining when list is empty//
  {
     top=n;
     top->next=NULL;

  }

  else                     // insetion at begining when node is not empty//
     {
         n->next=top;
         top=n;
     }
}

void pop()                   // deletion of node//
{
  struct node*ptr;

  if(top==NULL)
  {
    printf("stack underflow");
    return;
  }

   else                                // deletion of first node //
    {
       ptr=top;
       printf("delted data is %d",ptr->data);
       top=ptr->next;

       free(ptr);
     }
}


void display()                // display node//
{
    struct node*ptr;
 if(top==NULL)
 {
   printf("stack is empty");
 }

 else
   {
     ptr=top;
     while(ptr!=NULL)
          {
            printf("%d ",ptr->data);
            ptr=ptr->next;
          }
   }
}


int menu()                 // menu function//
{
  int ch;
    printf("\n1 for push (insert)");
    printf("\n2 for pop (delete)");
    printf("\n3 for display");
    printf("\n4 for exit");
    printf("\nenter the choice : ");
    scanf("%d",&ch);
    return(ch);
}

void main()               // main function //
{
 int n;

   printf("\t\t\t\t\tstack program with linked list\n");

  while(1)
  {
    switch(menu())
    {
       case 1:
             push();
             break;

        case 2:
             pop();
             break;

        case 3:
             display();
             break;

        case 4:
             exit(0);

        default:
             printf("\n wrong input");


    }
  }
}
