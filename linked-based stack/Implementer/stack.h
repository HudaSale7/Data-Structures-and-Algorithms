#define stackEntry char

typedef struct stacknode
{
    struct StackNode *next;
    stackEntry entry;
} stackNode;

typedef struct stack
{
    stackNode *top;
    int size;
} Stack;

void createStack(Stack *ps);

void push(stackEntry e, Stack *ps);

void pop(stackEntry *pe, Stack *ps);

int stackFull(Stack *ps);

int stackEmpty(Stack *ps);

void clearStack(Stack *ps);

void stackTop(stackEntry *pe, Stack *ps);

int stackSize(Stack *ps);

void copyStack(Stack *ps, Stack *pcs);

void traverseStack(Stack *ps, void (*pVisit)(stackEntry));
