#include <stdio.h>
#include <stdlib.h>
#include "fixed_queue.h"

struct FixedQueue {
    size_t size;
    int capacity;
    int lru_idx;
    int next_idx;
    int* arr;
};

FixedQueue* FixedQueue_New(size_t size) {
    FixedQueue* f = malloc(sizeof(FixedQueue));
    f->size = size;
    f->lru_idx = size - 1;
    f->next_idx = size - 1;
    f->arr = (int*) calloc(size, sizeof(int));
    return f;
}

void FixedQueue_Destroy(FixedQueue* f) {
    free(f->arr);
    free(f);
}

void FQ_Enqueue(FixedQueue* f, int val) {
    if (f->capacity == f->size) {
        printf("ERROR: Queue is full. Cannot Enqueue element.");
        exit(-1);
    }

    if (f->next_idx < 0) {
        f->next_idx = f->size-1;
    }

    printf("Enqueue at: %d\n", f->next_idx);

    *(f->arr + f->next_idx) = val;

    f->next_idx--;
    f->capacity++;
}

int FQ_Dequeue(FixedQueue* f) {
    if (f->capacity == 0) {
        printf("ERROR: Queue is empty. Cannot Dequeue element.");
        exit(-1);
    }

    if (f->lru_idx < 0) {
        f->lru_idx = f->size - 1;
    }

    int ret = *(f->arr + f->lru_idx);

    f->lru_idx--;
    f->capacity--;

    return ret;
}

int FQ_Full(FixedQueue* f) {
    return f->size == f->capacity;
}

int FQ_Empty(FixedQueue* f) {
    return f->capacity == 0;
}
