#include <stdio.h>
#include <stdlib.h>
#include "fixed_queue.h"

struct FixedQueue {
    size_t size;
    int capacity;
    int* arr;
};

FixedQueue* FixedQueue_New(size_t size) {
    FixedQueue* f = malloc(sizeof(FixedQueue));
    f->size = size;
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
    int idx = (f->size - f->capacity) - 1;

    printf("Enqueue at: %d\n", idx);
    *(f->arr + idx) = val;
    f->capacity++;
}

int FQ_Dequeue(FixedQueue* f) {
    if (f->capacity == 0) {
        printf("ERROR: Queue is empty. Cannot Dequeue element.");
        exit(-1);
    }
    int ret = *(f->arr + (f->size - 1));
    int stop = (f->size - f->capacity);
    for (int start = f->size - 1; start > stop; start--) {
        *(f->arr + start) = *(f->arr + (start - 1));
    }
    f->capacity--;
    return ret;
}

int FQ_Full(FixedQueue* f) {
    return f->size == f->capacity;
}

int FQ_Empty(FixedQueue* f) {
    return f->capacity == 0;
}
