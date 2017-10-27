#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

struct Node {
    Node* next;
    int key;
};

struct LinkedList {
    Node* head;
    Node* tail;
    int size;
};

LinkedList* LinkedList_New() {
    Node* head = malloc(sizeof(Node));
    Node* tail = malloc(sizeof(Node));

    LinkedList* l = malloc(sizeof(LinkedList));

    l->head = head;
    l->head->next = tail;

    l->tail = tail;
    l->tail->next = head;

    l->size = 0;

    return l;
}

void LinkedList_Destroy(LinkedList* l) {
    Node* head = l->head;
    Node* tail = l->tail;

    if (l->size > 0) {
        Node* curr = head->next;
        Node* prev;
        while(curr->next != tail) {
            prev = curr;
            curr = curr->next;
            free(prev);
        }
        free(curr);
    }

    free(l);
}

void PushFront(LinkedList* l, int key) {
    // create new node
    Node* n = malloc(sizeof(Node));
    // set data to node
    n->key = key;

    // save the current head next pointer
    Node* n_next = l->head->next;

    // set head next to the new node
    l->head->next = n;

    // set the new nodes next to heads old next
    n->next = n_next;

    if (n_next == l->tail) {
        l->tail->next = n;
    }

    l->size++;
}

int TopFront(LinkedList* l) {
    if (l->size > 0)
         return l->head->next->key;
    print_error("LinkedList is empty, can't TopFront on empty list.");
    exit(-1);
}

int PopFront(LinkedList* l) {
    if (l->size > 0) {
        Node* n = l->head->next;
        int ret = n->key;

        l->head->next = n->next;

        if (n->next == l->tail) {
            l->tail->next = l->head;
        }

        free(n);

        l->size--;
        return ret;
    }
    print_error("LinkedList is empty, can't PopFront on empty list.");
    exit(-1);
}

void PushBack(LinkedList* l, int key) {
    Node* new = malloc(sizeof(Node));
    new->key = key;

    Node* last = l->tail->next;

    last->next = new;

    new->next = l->tail;

    l->tail->next = new;

    l->size++;
}

int TopBack(LinkedList* l) {
    if (l->size > 0) {
        return l->tail->next->key;
    }
    print_error("LinkedList is empty, can't TopBack on empty list.");
    exit(-1);
}

int PopBack(LinkedList* l) {
    if (l->size > 0) {
       Node* pop = l->tail->next;

       Node* head = l->head;
       Node* tail = l->tail;

       Node* curr = head->next;

       while (curr != tail) {
        if (curr->next == pop) {
            curr->next = tail;
            tail->next = curr;
            break;
        }
        curr = curr->next;
       }

       int ret = pop->key;
       free(pop);

       return ret;
    }
    print_error("LinkedList is empty, can't PopBack on empty list.");
    exit(-1);
}

int find(LinkedList* l, int key) {
    Node* head = l->head;
    Node* tail = l->tail;

    Node* curr = head->next;
    int i = 0;
    while(curr != tail) {
        int val = curr->key;

        if (val == key) {
            return i;
        }
        curr = curr->next;
        i++;
    }
    return -1;
}

void print_list(LinkedList* l) {
    Node* head = l->head;
    Node* tail = l->tail;

    Node* curr = head->next;

    printf("[");
    while(curr != tail) {
        printf("%d",curr->key);
        curr = curr->next;
        if (curr != tail) printf(",");
    }
    printf("]\n");
}


void print_error(char msg[]) {
    printf("ERROR: %s\n", msg);
}

// ----
// Main
// ----
int main() {
    LinkedList* l = LinkedList_New();

    printf("push front 2\n");
    PushFront(l, 2);
    print_list(l);

    printf("push front 1\n");
    PushFront(l, 1);
    print_list(l);

    printf("push back 3\n");
    PushBack(l, 3);
    print_list(l);

    printf("push back 4\n");
    PushBack(l, 4);
    print_list(l);

    printf("Front = %d\n", TopFront(l));
    printf("Back = %d\n", TopBack(l));
    printf("Find index of key = 4: %d\n", find(l,4));

    printf("push back 4\n");
    PushBack(l, 4);
    print_list(l);

    printf("pop back = %d\n", PopBack(l));
    print_list(l);

    printf("pop front = %d\n", PopFront(l));
    print_list(l);

    printf("pop front = %d\n", PopFront(l));
    print_list(l);

    LinkedList_Destroy(l);
}
