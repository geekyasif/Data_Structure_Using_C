                              // stack program with array //

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100


void push();
void pop();
void display();

int top=-1,i,stack[MAX];

void push()                        // for insert data//
{
  if(top==MAX-1)
  {
    printf("\nstack overflow\n");
  }

  else
    {
      top++;
      printf("\nenter the data : ");
      scanf("%d",&stack[top]);
    }
}


void pop()                               // for delete data//
{
  if(top==-1)
  {
    printf("\nstack underflow\n");
  }

  else
  {
     printf("\ndeleted data is %d",stack[top]);
     top--;
  }

}


void display()           // for display//
{
  if(top==-1)
  {
    printf("\nlist is empty\n");
  }

  else
  {
    for(i=0;i<=top;i++)
    {
      printf("%d\t",stack[i]);
    }
  }
}


int menu()              // menu function//
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

   printf("\t\t\t\t\tstack program with array\n");

  while(1)
  {
    switch(menu())
    {
       case 1:
              printf("\nhow many stack you want to create enter number : ");
              scanf("%d",&n);
              if(n>MAX)
                {
                  printf("\nenter number is greater than system number please enter number under 100\n");
                 }

              else
              {
                   for(i=0;i<n;i++)
                   {
                     push();
                   }
              }
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
