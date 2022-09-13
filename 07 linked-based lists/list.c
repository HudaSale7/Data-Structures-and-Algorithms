#include "list.h"
#include <stdlib.h>

void createList (List *pList) {
    pList->head = NULL;
    pList->size = 0;
}

int listEmpty(List *pList) {
    return !pList->size;
}

int listFull(List *pList) {
    return 0;
}

void destroyList(List *pList) {
    listNode *pNode = pList->head;
    while (pNode)
    {
        pNode = pNode->next;
        free(pList->head);
        pList->head = pNode;
    }
    pList->size = 0;
}

int listSize(List *pList) {
    return pList->size;
}

void insertList(int pos, listEntry e, List *pList) {
    listNode *before = pList->head;
    listNode *after = (listNode *)malloc(sizeof(listNode));
    after->entry = e;
    after->next = NULL;
    if (pos == 0)
        pList->head = after;
    else {
        for (int i = 0; i < pos - 1; i++)
            before = before->next;
        after->next = before->next;
        before->next = after;
    }
    pList->size++;
}


void deleteList(int pos, listEntry *pe, List *pList) {
    listNode *before = pList->head;
    listNode *pNode;
    if (pos == 0)
    {
        *pe = pList->head->entry;
        pList->head = pList->head->next;
        free(before);
    } else {
        for (int i = 0; i < pos - 1; i++)
            before = before->next;
        pNode = before->next;
        before->next = pNode->next;
        *pe = pNode->entry;
        free(pNode);
    }
    pList->size--;
}


void traverseList(List *pList, void (pVisit)(listEntry)) {
    listNode *pNode = pList->head;
    while (pNode)
    {
        (*pVisit)(pNode->entry);
        pNode = pNode->next;
    }
}

void retrieveList(int pos, listEntry *pe, List *pList) {
    listNode *pNode = pList->head;
    for (int i = 0; i < pos; i++)
        pNode = pNode->next;
    *pe = pNode->entry;
}

void replaceList(int pos, listEntry e, List *pList) {
    listNode *pNode = pList->head;
    for (int i = 0; i < pos; i++)
        pNode = pNode->next;
    pNode->entry = e;
}

