#include <stdio.h>
#include "./linkedlists/linkedlist.h"
#include "./queue/queue.h"
#include "./arrays/vector/vector.h"

void test_vector() {
    Vector* v = Vector_new();

    for(int i = 0; i < 5; i++) {
        Push_back(v, i);
    }

    print_vector(v);

    Remove(v, Size(v) - 1);
    print_vector(v);

    Remove(v, 0);
    print_vector(v);

    Remove(v, 1);
    print_vector(v);

    Remove(v, 0);
    print_vector(v);

    Remove(v, 0);
    print_vector(v);

    Vector_destroy(v);

    v = Vector_new();

    for (int i = 0; i < 10; i++) {
        Push_back(v,i);
    }

    print_vector(v);

    printf("idx v[5] = %d\n", Get(v,5));
    printf("setting v[5] to be 1000\n");
    Set(v, 5, 1000);
    printf("idx v[5] = %d\n", Get(v,5));

    print_vector(v);

    Vector_destroy(v);
}

void test_linkedlist() {
    LinkedList* l = LinkedList_New();

    printf("push front 2\n");
    PushFront(l, 2);
    print_list(l);

    printf("push front 1\n");
    PushFront(l, 1);
    print_list(l);

    printf("reverse\n");
    Reverse(l);
    print_list(l);

    printf("reverse\n");
    Reverse(l);
    print_list(l);

    printf("push back 3\n");
    PushBack(l, 3);
    print_list(l);

    printf("push back 4\n");
    PushBack(l, 4);
    print_list(l);

    printf("Front = %d\n", TopFront(l));
    printf("Back = %d\n", TopBack(l));
    printf("Find index of key = 4: %d\n", Find(l,4));

    printf("push back 4\n");
    PushBack(l, 4);
    print_list(l);

    printf("push back 4\n");
    PushBack(l, 4);
    print_list(l);

    printf("reverse\n");
    Reverse(l);
    print_list(l);

    printf("reverse\n");
    Reverse(l);
    print_list(l);

    printf("erase 3\n");
    Erase(l,3); print_list(l);

    printf("pop back = %d\n", PopBack(l));
    print_list(l);

    printf("pop front = %d\n", PopFront(l));
    print_list(l);

    printf("pop front = %d\n", PopFront(l));
    print_list(l);

    printf("erase 4\n");
    Erase(l,4);
    print_list(l);

    printf("reverse\n");
    Reverse(l);
    print_list(l);

    printf("reverse\n");
    Reverse(l);
    print_list(l);

    printf("erase 4\n");
    Erase(l,4);
    print_list(l);

    printf("reverse\n");
    Reverse(l);
    print_list(l);

    printf("reverse\n");
    Reverse(l);
    print_list(l);

    printf("empty? %d\n", Empty(l));

    LinkedList_Destroy(l);
}

void test_queue() {
    Queue* q = Queue_New();
    for (int i = 0; i < 20; i++) {
        Enqueue(q,i);
    }

    for (int i = 0; i < 20; i++) {
        printf("Dequeue: %d\n", Dequeue(q));
    }

    printf("Queue empty? %d\n", EmptyQueue(q));

    Queue_Destroy(q);
}

// ----
// Main
// ----
int main() {
    //test_linkedlist();
    //test_vector();
    test_queue();
}
