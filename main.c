#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "heap.h"

#define ARRAY_SIZE 50
#define MAX_VALUE 100

int main() {
    // Inicializar a semente para números aleatórios
    srand(time(NULL));

    // Criar um heap com capacidade inicial de 10
    Heap* heap = heap_construct(10);

    // Inserir 50 elementos aleatórios no heap
    for (int i = 0; i < ARRAY_SIZE; i++) {
        int value = rand() % MAX_VALUE;
        heap_insert(heap, value);
    }

    // Extração e impressão dos elementos em ordem crescente
    printf("Elementos em ordem crescente:\n");
    while (!isEmpty(heap)) {
        int min = extractMin(heap);
        printf("%d ", min);
    }

    printf("\n");

    // Liberar memória do heap
    heap_destroy(heap);

    return 0;
}
