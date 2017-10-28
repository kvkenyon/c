typedef struct LinkedList LinkedList;
typedef struct Node Node;

LinkedList* LinkedList_New();
void LinkedList_Destroy(LinkedList* l);
void PushFront(LinkedList* l, int key);
int TopFront(LinkedList* l);
int PopFront(LinkedList* l);
void PushBack(LinkedList* l, int key);
int TopBack(LinkedList* l);
int Find(LinkedList* l, int key);
void Erase(LinkedList* l, int key);
int Empty(LinkedList* l);
void AddBefore(LinkedList* l, Node* n, int key);
void AddAfter(LinkedList* l, Node* n, int key);
void Reverse(LinkedList* l);
void print_error(char msg[]);
