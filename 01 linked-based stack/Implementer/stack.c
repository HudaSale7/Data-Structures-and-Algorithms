#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
void createStack(Stack *ps) {
    ps->top = NULL;
    ps->size = 0;
}

void push(stackEntry e, Stack *ps) {
    if (ps->top == NULL)
        ps->min = e;
    else
    {
        if (e < ps->min)
            ps->min = e;
    }
    stackNode *pNode;
    pNode = (stackNode*) malloc(sizeof(stackNode));
    pNode->entry = e;
    pNode->next = ps->top;
    ps->top = pNode;
    ps->size++;
}

void pop(stackEntry *pe, Stack *ps) {
    stackNode *pNode = ps->top;
    *pe = pNode->entry;
    ps->top = pNode->next;
    free(pNode);
    ps->size--;
}

int stackFull(Stack *ps) {
    return 0;
}

int stackEmpty(Stack *ps) {
    return ps->top == NULL;
}


void clearStack(Stack *ps) {
    stackNode *pNode;
    while (ps->top)
    {
        pNode = ps->top;
        ps->top = pNode->next;
        free(pNode);
    }
    ps->size = 0;
}


void stackTop(stackEntry *pe, Stack *ps) {
    *pe = ps->top->entry;
}


int stackSize(Stack *ps) {
    return ps->size;
}


void copyStack(Stack *ps, Stack *pcs) {
    clearStack(pcs);
    stackNode *pNode = ps->top;
    stackNode *pNodeCopied = (stackNode *)malloc(sizeof(stackNode));
    pcs->top = pNodeCopied;
    pcs->size = 1;
    pNodeCopied->entry = pNode->entry;
    pNode = pNode->next;
    while (pNode)
    {
        pNodeCopied->next = (stackNode *)malloc(sizeof(stackNode));
        pNodeCopied = pNodeCopied->next;
        pNodeCopied->entry = pNode->entry;
        pNode = pNode->next;
        pcs->size++;
    }
    pNodeCopied->next = NULL;
    }


void traverseStack(Stack *ps, void (*pVisit)(stackEntry)) {
    stackNode *pNode = ps->top;
    while (pNode)
    {
        (*pVisit)(pNode->entry);
        pNode = pNode->next;
    }
}

char findMin (Stack *ps) {
    return ps->min;
}
