                           // circular linked list//

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void display();
void insertatbeg();                   // function declaration//
void insertbeforebeg();
void insertatlast();
void insertatafter();
void insertatbefore();
void delatbeg();
void delatlast();
void delparticular();

struct node{                         //data type for create node//
          int data;
          struct node* next;
  };

struct node* last=NULL;

struct node* createnode()            // defining name and memory declatarion for node//
{
    struct node*t;
    t=(struct node*)malloc(sizeof(struct node));
    return(t);
 }

 void insertatbeg()            // insert node at begining when list is empty//
 {
   struct node*n,*ptr;
   n=createnode();
   printf("enter number to insert : ");
   scanf("%d",&n->data);

     last=n;
     last->next=last;

 }

 void insertbeforebeg()           // insert node at begining when list is not empty//
 {
     struct node*n,*ptr;
   n=createnode();
   printf("enter number to insert : ");
   scanf("%d",&n->data);

   n->next=last->next;
   last->next=n;


 }

 void insertatlast()  // insert a node at last of the list //
 {
     struct node*n,*ptr;
   n=createnode();
   printf("enter number to insert : ");
   scanf("%d",&n->data);

   n->next=last->next;
   last->next=n;
   last=n;

 }

 void insertatafter()        //insert a node after a node //
 {
     struct node*n,*ptr;
     int val;
   n=createnode();
   printf("\nafter which node you want inseert a new node :");
   scanf("%d",&val);
   printf("\nenter number to insert : ");
   scanf("%d",&n->data);

   if (val==last->data)           // when new node instert only after the last node //
   {
       n->next=last->next;
   last->next=n;
   last=n;

   }

   else                               // when new node insert after any node except last node //
   {

    ptr=last->next;
   while(ptr->data!=val)
   {
       ptr=ptr->next;
   }
     n->next=ptr->next;
     ptr->next=n;

   }
 }

 void insertatbefore()     //insert a node before any node //
 {

     struct node*n,*t,*ptr,*pptr;
     int val;
   n=createnode();
   printf("\nafter which node you want inseert a new node :");
   scanf("%d",&val);
   printf("\nenter number to insert : ");
   scanf("%d",&n->data);

   t=last->next;                     // insert node only before the first node//
   if (val==t->data)
   {
      n->next=last->next;
   last->next=n;

   }

     else                              // insert node before any node except first node //
        {
          pptr=ptr=last->next;
           while(ptr->data!=val)
             {
               pptr=ptr;
               ptr=ptr->next;
             }
               pptr->next=n;
               n->next=ptr;
        }

 }


 void delatbeg()         // delete the first node //
 {
     struct node*ptr;
     if(last==NULL)
     {
         printf("list is empty ,add some node to delete");
     }

     else
        {
          ptr=last->next;
           last->next=ptr->next;
           free(ptr);

        }


 }


 void delatlast()         // delete the last node //
 {
     struct node*ptr,*pptr;
     if(last==NULL)
     {
         printf("list is empty ,add some node to delete");
     }

     else
        {
           pptr=ptr=last->next;
               while(ptr->next!=last->next)
               {
                   pptr=ptr;
                   ptr=ptr->next;
               }

               pptr->next=ptr->next;
               last=pptr;
               free(ptr);

        }

 }


 void delparticular()                // delete any node in the list//
 {
     struct node*pptr,*ptr,*t;
     int val;
     printf("\nenter the node you want to delete : ");
     scanf("%d",&val);
     t=last->next;             // if the node is first//
     if(val==t->data)
      {
         delatbeg();
      }

     else if(val==last->data)     // if the node is last//
      {
         delatlast();
      }

     else                           // or any node except first and last//

        {
            pptr=ptr=last->next;
            while(ptr->data!=val)
            {
                pptr=ptr;
                ptr=ptr->next;
            }

            pptr->next=ptr->next;
            free(ptr);
        }

      }

 void display()            // function for display node//
{
  struct node*t;

  if(last==NULL)
  {
    printf("\nlist is empty");
  }

  else
      {
        t=last->next;
        do
        {

             printf("%d ",t->data);
             t=t->next;
      }while(t!=last->next);
      }

}


int menu()             // list or menu function which display on screen//
{
  int n;

  printf("\n 1 for insert the node at begining when list is empty");
  printf("\n 2 view list");
  printf("\n 3 for exit");
  printf("\n 4 insert the node at begining when list is not empty");
  printf("\n 5 insert the node at last");
  printf("\n 6 inseert a node after any node");
  printf("\n 7 inseert a node before any node");
  printf("\n 8 delete the first node");
  printf("\n 9 delete the last node");
  printf("\n 10 delete any node in the list");
  printf("\n enter choice : ");
  scanf("%d",&n);

  return(n);
}

int main()           // main function//
{
    printf("\t\t\t\t\tcircular linked list\n");
  while(1)
  {
    switch(menu())
    {
      case 1:
          insertatbeg();
          break;

          case 2:
            display();
            break;

            case 3:
               exit(0);
            case 4:
                insertbeforebeg();
                break;
            case 5:
                 insertatlast();
                 break;
            case 6:
                  insertatafter();
                  break;
            case 7:
                   insertatbefore();
                   break;

            case 8:
                   delatbeg();
                   break;
            case 9:
                   delatlast();
                   break;
            case 10:
                  delparticular();
                  break;

               default:
                  printf("wrong input");

    }

  }

}
