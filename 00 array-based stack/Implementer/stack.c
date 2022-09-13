#include "stack.h"

void createStack(Stack *ps) {
    ps->top = 0;
}

void push(stackEntry e, Stack *ps) {
    ps->entry[ps->top++] = e;
}

void pop(stackEntry *pe, Stack *ps) {
    *pe = ps->entry[--ps->top];
}

int stackFull(Stack *ps) {
    if (ps->top == MAXSTACK)
        return 1;
    else
        return 0;
}

int stackEmpty(Stack *ps) {
    if (ps->top == 0)
        return 1;
    else
        return 0;
}

void clearStack(Stack *ps) {
    ps->top = 0;
}

void stackTop(stackEntry *pe, Stack *ps) {
    *pe = ps->entry[ps->top - 1];
}

int stackSize(Stack *ps) {
    return ps->top;
}

void copyStack(Stack *ps, Stack *pcs) {
    pcs->top = ps->top;
    for (int i = 0; i < ps->top; i++)
    {
        pcs->entry[i] = ps->entry[i];
    }
}

void traverseStack(Stack *ps, void (*pVisit)(stackEntry)) {
    for (int i = ps->top - 1; i >= 0; i--)
    {
        (*pVisit)(ps->entry[i]);
    }
}
