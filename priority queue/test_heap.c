#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main()
{
    int n, i, op, X;
    PriorityQueue H;

    scanf("%d", &n);
    H = Initialize(n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            scanf("%d", &X);
            Insert(X, H);
            break;
        case 0:
            printf("%d ", DeleteMin(H));
            break;
        }
    }
    printf("\nInside H:");
    for (i = 1; i <= H->Size; i++)
        printf(" %d", H->Elements[i]);
    system("pause");
    return 0;
}