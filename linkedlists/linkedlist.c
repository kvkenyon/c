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
    print_error_ll("LinkedList is empty, can't TopFront on empty list.");
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
    print_error_ll("LinkedList is empty, can't PopFront on empty list.");
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
    print_error_ll("LinkedList is empty, can't TopBack on empty list.");
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

       l->size--;

       int ret = pop->key;
       free(pop);

       return ret;
    }
    print_error_ll("LinkedList is empty, can't PopBack on empty list.");
    exit(-1);
}

int Find(LinkedList* l, int key) {
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

void Erase(LinkedList* l, int key) {
    if (l->size == 0) {
        print_error_ll("LinkedList is empty, can't Erase on empty list.");
        return;
    }

    Node* head = l->head;
    Node* tail = l->tail;

    Node* curr = head->next;
    Node* prev = head;

    while (curr != tail) {
        if (curr->key == key) {
            // remove it
            prev->next = curr->next;
            if (curr->next == tail)
                tail->next = prev;
            l->size--;
            free(curr);
            break;
        }

        prev = curr;
        curr = curr->next;
    }
}

int Empty(LinkedList* l) {
    return l->size == 0;
}

void AddBefore(LinkedList* l, Node* n, int key) {
    Node* new = malloc(sizeof(Node));
    new->key = key;

    Node* head = l->head;
    Node* tail = l->tail;

    Node* curr = head->next;
    Node* prev = head;
    while (curr != tail) {
        if (curr == n) {
            prev->next = new;
            new->next = curr;
            break;
        }
        curr = curr->next;
    }
}

void AddAfter(LinkedList* l, Node* n, int key) {
    Node* new = malloc(sizeof(Node));
    new->key = key;

    if(n->next == l->tail) {
        l->tail->next = new;
    }

    new->next = n->next;
    n->next = new;
}

void Reverse(LinkedList* l) {
    if (l->size == 0) return;

    Node* head = l->head;
    Node* tail = l->tail;

    Node* prev = head->next;
    Node* curr = prev->next;

    Node* next;

    tail->next = prev;
    prev->next = tail;

    while(curr != tail) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head->next = prev;
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


void print_error_ll(char msg[]) {
    printf("ERROR: %s\n", msg);
}

