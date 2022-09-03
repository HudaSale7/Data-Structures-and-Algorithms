#define MAXSTACK 100
#define stackEntry char

typedef struct stack
{
    stackEntry entry[MAXSTACK];
    int top;
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
