#ifndef HEAP_H
#define HEAP_H

typedef int data_type;

typedef struct {
    data_type* arr;     
    int size;  
    int capacity; 
} Heap;

Heap* heap_construct(int capacity);
void heap_destroy(Heap* heap);
void heap_insert(Heap* heap, data_type value);
data_type extractMin(Heap* heap);
data_type getMin(Heap* heap);
int isEmpty(Heap* heap);
int isFull(Heap* heap);
void swap(Heap *heap, int idxNew, int idxOld);
void bubble_up(Heap *heap);
void bubble_down(Heap *heap, int idx);

#endif // HEAP_H
