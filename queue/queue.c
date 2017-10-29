#include <stdio.h>
#include <stdlib.h>
#include "../linkedlists/linkedlist.h"
#include "queue.h"

struct Queue {
    LinkedList* l;
};

Queue* Queue_New() {
    Queue* q = malloc(sizeof(Queue));
    q->l = LinkedList_New();
    return q;
}

void Queue_Destroy(Queue* q) {
    free(q);
}

void Enqueue(Queue* q, int key) {
    PushBack(q->l, key);
}

int Dequeue(Queue* q) {
    return PopFront(q->l);
}

int EmptyQueue(Queue* q) {
    print_list(q->l);
    return Empty(q->l) == 1;
}
