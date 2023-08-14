#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

Heap* heap_construct(int capacity){

    Heap *heap = (Heap*) malloc(sizeof(Heap));

    heap->capacity = capacity;
    heap->size = 0;

    heap->arr = (data_type*) malloc(sizeof(data_type)*capacity);

    return heap;
}

void heap_destroy(Heap* heap){
    free(heap->arr);
    free(heap);
}

void heap_insert(Heap* heap, data_type value){

    if(isFull(heap)){
        heap->capacity *= 2;
        heap->arr = (data_type*) realloc(heap->arr, sizeof(data_type) * heap->capacity);
    }

    heap->arr[heap->size] = value;
    
    bubble_up(heap);

    heap->size++;
}

int isEmpty(Heap* heap){
    return heap->size == 0;
}

int isFull(Heap* heap){
    return heap->size >= heap->capacity -1;
}

void swap(Heap *heap, int idxNew, int idxOld){

    data_type aux = heap->arr[idxOld];

    heap->arr[idxOld] = heap->arr[idxNew];
    
    heap->arr[idxNew] = aux;
}

void bubble_up(Heap *heap){

    int idx = heap->size;
    int pai = (idx -1)/2;

    while(idx > 0 && heap->arr[idx] < heap->arr[pai]){
        
        swap(heap, idx, pai);

        idx = pai;
        pai = (idx -1)/2;
    }
}

data_type extractMin(Heap* heap){

    if(isEmpty(heap)){
        printf("Heap vazio");
        exit(1);
    }

    data_type raiz = heap->arr[0];

    heap->arr[0] = heap->arr[heap->size-1];
    heap->size--;
    
    bubble_down(heap, 0);

    return raiz;
}

void bubble_down(Heap *heap, int idx){

    int left_child = 2 * idx + 1;
    int right_child = 2 * idx + 2;
    int smallest = idx;

    if(left_child < heap->size && heap->arr[left_child] < heap->arr[smallest])
        smallest = left_child;
    
    if(right_child < heap->size && heap->arr[right_child] < heap->arr[smallest])
        smallest = right_child;
    
    if(idx != smallest){
        swap(heap, smallest, idx);
        bubble_down(heap, smallest);
    }
}

data_type getMin(Heap* heap){
    return heap->arr[0];
}