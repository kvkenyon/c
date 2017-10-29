typedef struct Queue Queue;

Queue* Queue_New();
void Queue_Destroy(Queue* q);
void Enqueue(Queue* q, int key);
int Dequeue(Queue* q);
int EmptyQueue(Queue* q);
