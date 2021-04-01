/********************************************************************************
* @File name: heap.c
* @Version: 1.1
* @Date: 2021-03-31
* @Description: 1.实现heap的基操
                (1) 数据结构的定义
                (2) 初始化
                (3) 插入
                (4) 删除
********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

typedef int ElementType;
#define MinData -1

typedef struct Heap *PriorityQueue;

/*initial the heap with MaxElement*/
PriorityQueue Initialize(int MaxElements)
{
    PriorityQueue H;
    H = (PriorityQueue)malloc(sizeof(struct Heap));
    /* Allocate the array plus one extra for sentinel */
    H->Elements = malloc(sizeof(ElementType) * (MaxElements + 1));
    if (H->Elements == NULL)
    {
        return 0;
    }
    H->Capacity = MaxElements;
    H->Size = 0;
    H->Elements[0] = MinData; /* set the sentinel */
    return H;
}

/*Insert one element to the heap*/
void Insert(ElementType X, PriorityQueue H)
{
    int p = ++H->Size;  /*H->Size increment*/
    H->Elements[p] = X; /*Elements[Size] = X:first we insert at the tail*/
    //PercolateUp(p, H);
    int i;
    for (i = p; H->Elements[i / 2] > X; i /= 2)
    {
        H->Elements[i] = H->Elements[i / 2];
    }
    H->Elements[i] = X;
}

/*Delete the minElement from the heap*/
ElementType DeleteMin(PriorityQueue H)
{
    ElementType MinEle;
    MinEle = H->Elements[1];
    H->Elements[1] = H->Elements[H->Size--];
    ElementType X = H->Elements[1]; /*X should percolate down*/
    // PercolateDown(1, H);
    int i, Child;
    for (i = 1; 2 * i <= H->Size; i = Child) /*each step find the minimum one in two children*/
    {
        Child = 2 * i;
        if (Child != H->Size && H->Elements[Child] > H->Elements[Child + 1])
            Child++;
        if (H->Elements[Child] > X)
            break;
        else
        {
            H->Elements[i] = H->Elements[Child];
        }
    }
    H->Elements[i] = X;
    return MinEle;
}
