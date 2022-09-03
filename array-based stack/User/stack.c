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
