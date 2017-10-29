#include <stdlib.h>
#include <stdio.h>
#include "./vector.h"

const char OUT_OF_MEMORY[] = "Out of Memroy";
const char OUT_OF_BOUNDS[] = "Array index out of bounds";

const int DEFAULT_CAPACITY = 50;

struct Vector {
    int* addr;
    int size;
    int capacity;
};

Vector* Vector_new() {
    Vector* v = malloc(sizeof(Vector));
    if (v == 0) {
        print_error(OUT_OF_MEMORY);
        exit(-1);
    }

    v->addr = (int*) calloc(DEFAULT_CAPACITY, sizeof(int));

    if (v->addr == 0) {
        print_error(OUT_OF_MEMORY);
        exit(-1);
    }

    v->size = 0;
    v->capacity = DEFAULT_CAPACITY;
    return v;
}

void Vector_destroy(Vector* v) {
    free(v->addr);
    free(v);
}

int Get(Vector* v, int i) {
    if (i < 0 || i >= v->size) {
        print_error(OUT_OF_BOUNDS);
        exit(-1);
    }
    return *(v->addr + i*sizeof(int));
}

void Set(Vector* v, int i, int val) {
    if (i < 0 || i >= v->size) {
        print_error(OUT_OF_BOUNDS);
        exit(-1);
    }
    *(v->addr + i*sizeof(int)) = val;
}

void Push_back(Vector* v, int val) {
    printf("Pushing %d\n", val);

    if (v->capacity == v->size) {
        printf("Capacity of %d reached, resizing to %d\n", v->capacity, 2*v->capacity);
        int* new_addr = (int*)calloc(2*v->capacity, sizeof(int));

        for (int i = 0; i < v->size; i++) {
            *(new_addr + i) = *(v->addr + i);
        }

        v->addr = new_addr;
    }

    *(v->addr + v->size*sizeof(int)) = val;
    ++(v->size);
}

void Remove(Vector* v, int i) {
    printf("Remove index %d\n", i);
    if (i < 0 || i >= v->size) {
        print_error(OUT_OF_BOUNDS);
        exit(-1);
    }

    if (i == (v->size - 1)) {
        *(v->addr + i*sizeof(int)) = 0;
    } else {
        for (int j = i+1; j < v->size; j++) {
            *(v->addr + (j-1)*sizeof(int)) =
                *(v->addr + j*sizeof(int));
        }
    }
    v->size = v->size - 1;
}

int Size(Vector* v) {
    return v->size;
}

void print_vector(Vector* v) {
    printf("[");
    for (int i = 0; i < v->size; i++) {
        printf("%d", *(v->addr + i*sizeof(int)));
        if (i != v->size - 1) printf(", ");
    }
    printf("]\n");
}

void print_error(const char msg[]) {
    fprintf(stderr, "ERROR: %s\n", msg);
}

