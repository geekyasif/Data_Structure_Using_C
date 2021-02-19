#include <stdio.h>
#include <stdlib.h>

int main()
{

    int* ptr;
    int n, i;

    printf("\nEnter number of elements: ");
    scanf("%d",&n);

    ptr = (int*)malloc(n * sizeof(int));

    if (ptr == NULL)
       {
        printf("\nMemory not allocated.");
        exit(0);
       }

    else
      {
        printf("\nMemory successfully allocated using malloc.\n");
         for (i = 0; i < n; ++i)
           {
            ptr[i] = i + 1;
           }

        printf("\nThe elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }
    }

    return 0;
}
