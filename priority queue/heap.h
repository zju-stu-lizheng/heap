#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
#define MinData -1

typedef struct Heap *PriorityQueue;
struct Heap
{
    ElementType *Elements; /*data domain*/
    int Capacity;          /*the maximum number of element can store*/
    int Size;              /*the current number of element*/
};

PriorityQueue Initialize(int MaxElements);      /*initial the heap with MaxElement*/
void Insert(ElementType X, PriorityQueue H);    /*Insert one element to the heap*/
ElementType DeleteMin(PriorityQueue H);         /*Delete the minElement from the heap*/