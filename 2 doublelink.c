			                    // double linked list//

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void insert();
void afterinsert();
void beforeinsert();
void display();
void delatbeg();
void delatlast();
void delparticularnode();

struct node{                                // node datatype//
          struct node* prev;
         int data;
        struct node* next;
};
 struct node* start=NULL;

struct node* createnode()               //node creation in memory//
{
 struct node*t;
 t=(struct node*)malloc(sizeof(struct node));
 return(t);
}

void insert()            //insert node at the begining and last//
 {
   struct node*m,*ptr;

   m=createnode();

   printf("enter data :");
   scanf("%d",&m->data);

    m->next=NULL;

    if(start==NULL)
    {
      m->prev=NULL;
      start=m;


      }
      else
      {
       ptr=start;

        while(ptr->next!=NULL)
             ptr=ptr->next;

         ptr->next=m;
         m->prev=ptr;
 }
}

 void afterinsert()      //insert a node after a node//
 {
  struct node*t,*n,*ptr;
  int pos;
  printf("where you want to insert a node : ");
  scanf("%d",&pos);
  n=createnode();
  printf("enter number to be inserted : ");
  scanf("%d",&n->data);
  t=start;
  while(t->data!=pos)
  {
   t=t->next;
   }
   n->next=t->next;
   t->next=n;
   n->prev=ptr;
 }

 void beforeinsert()      //insert a node before a node//
 {
  struct node*pptr,*ptr,*n,*t;
  int pos;
  printf("where you want to insert a node :");
  scanf("%d",&pos);
  n=createnode();
  printf("enter new node to be inserted :");
  scanf("%d",&n->data);
   t=start;
  if(t->data==pos)
    {
      n->prev=NULL;
      n->next=t;
      t->prev=n;
      start=n;

      }
      else
      {
      ptr=start;
  while(ptr->data!=pos)
   {
    ptr=ptr->next;
    }
      ptr->prev->next=n;
      n->prev=ptr->prev;
      n->next=ptr;
      ptr->prev=n;

    }

  }

 void delatbeg()       //delete the first node//
{
  struct node*t;
  t=start;
         start=t->next;
         free(t);

}

 void delatlast()                //delete the last node//
 {
   struct node*t;

   t=start;

       while(t->next!=NULL)           // delete last node except first node//
        {
          t=t->next;
        }
            t->prev->next=t->next;
            free(t);
 }


  void delparticularnode()  //delete the particular node//
  {
   struct node*ptr;
   int val;
   printf("enter the node you want to delete :");
   scanf("%d",&val);

   ptr=start;
   if(ptr->data==val)
      {
         delatbeg();

      }

       else
        {
            while(ptr->data!=val)
            {
                ptr=ptr->next;
            }

             if(ptr->next==NULL)
               {
                 delatlast();
               }
             else
               {
                 ptr->prev->next=ptr->next;
                 ptr->next->prev=ptr->prev;

               }
 }
}

void display()           // display function//
{
 struct node*t;

 if(start==NULL)
 {
  printf("list is empty");
  }

  else
  {
   t=start;
   while(t!=NULL)
     {
     printf("%d ",t->data);
     t=t->next;
     }
     }
  }

 int menu()               //menu function//
 {
   int m;
   printf("\n1 for insert a node");
   printf("\n2 for display node");
   printf("\n3 for exit");
   printf("\n4 for delete the first node");
   printf("\n5 for delete the last node");
   printf("\n6 for insert a node after a node");
   printf("\n7 for insert a node before a node");
   printf("\n8 for delete a particular node");
   printf("\n enter choice :");
   scanf("%d",&m);
   return(m);
}

int main()                // main function//
   {
    printf("\t\t\t\tdouble linked list\n");
    while(1)
    {
     switch (menu())
     {
      case 1:
	    insert();
	    break;

     case 2:
	     display();
	     break;

       case 3:
	     exit(0);
       case 4:
	  delatbeg();
	  break;
       case 5:
	     delatlast();
	     break;

       case 6:
	      afterinsert();
	      break;
       case 7:
	     beforeinsert();
	     break;
       case 8:
	     delparticularnode();
	     break;

	     default: printf("wrong input");


     }
    }
    }
