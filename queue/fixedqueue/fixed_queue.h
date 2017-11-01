typedef struct FixedQueue FixedQueue;

FixedQueue* FixedQueue_New(size_t size);
void FixedQueue_Destroy(FixedQueue* f);
void FQ_Enqueue(FixedQueue* f, int val);
int FQ_Dequeue(FixedQueue* f);
int FQ_Full(FixedQueue* f);
int FQ_Empty(FixedQueue* f);
