typedef struct Vector Vector;

Vector* Vector_new();
void Vector_destroy(Vector* v);
int Get(Vector* v, int i);
void Set(Vector* v, int i, int val);
void Push_back(Vector* v, int val);
void Remove(Vector* v, int i);
int Size(Vector* v);
void print_vector(Vector *v);
void print_error(const char msg[]);
