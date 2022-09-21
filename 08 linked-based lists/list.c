#include "list.h"
#include <stdlib.h>

void createList (List *pList) {
    pList->head = NULL;
    pList->current = pList->head;
    pList->currentPos = 0;
    pList->size = 0;
}

int listEmpty(List *pList) {
    return !pList->size;
}

int listFull(List *pList) {
    return 0;
}

void destroyList(List *pList) {
    pList->current = pList->head;
    while (pList->current)
    {
        pList->current = pList->current->next;
        free(pList->head);
        pList->head = pList->current;
    }
    pList->size = 0;
}

int listSize(List *pList) {
    return pList->size;
}

void insertList(int pos, listEntry e, List *pList) {
    listNode *after = (listNode *)malloc(sizeof(listNode));
    after->entry = e;
    after->next = NULL;
    if (pos == 0) {
        after->next = pList->head;
        pList->head = after;
    }
    else {
        if (pList->currentPos <= pos) {
        pList->current = pList->head;
        pList->currentPos = 0;
        }
        for (; pList->currentPos != pos - 1; pList->currentPos++)
            pList->current = pList->current->next;
        after->next = pList->current->next;
        pList->current->next = after;
    }
    pList->size++;
}


void deleteList(int pos, listEntry *pe, List *pList) {
    listNode *pNode = pList->head;
    if (pos == 0)
    {
        *pe = pList->head->entry;
        pList->head = pList->head->next;
        free(pNode);
    } 
    else {
        if (pList->currentPos <= pos) {
        pList->current = pList->head;
        pList->currentPos = 0;
        }
        for (; pList->currentPos != pos - 1; pList->currentPos++)
            pList->current = pList->current->next;
        pNode = pList->current->next;
        pList->current->next = pNode->next;
        *pe = pNode->entry;
        free(pNode);
    }
    pList->size--;
}


void traverseList(List *pList, void (pVisit)(listEntry)) {
    listNode *pNode = pList->head;
    while (pNode) {
        (*pVisit)(pNode->entry);
        pNode = pNode->next;
    }
}

void retrieveList(int pos, listEntry *pe, List *pList) {
    if (pList->currentPos <= pos) {
        pList->current = pList->head;
        pList->currentPos = 0;
    } 
    for (; pList->currentPos != pos; pList->currentPos++)
        pList->current = pList->current->next;
    *pe = pList->current->entry;
}


void replaceList(int pos, listEntry e, List *pList) {
    if (pList->currentPos <= pos) {
        pList->current = pList->head;
        pList->currentPos = 0;
    } 
    for (; pList->currentPos != pos; pList->currentPos++)
        pList->current = pList->current->next;
    pList->current->entry = e;
}


int sequentialSearch(listEntry e, List *pList) {
    listNode *pNode = pList->head;
    for (int i = 0; i < pList->size; i++)
    {
        if (e == pNode->entry)
            return i;
        pNode = pNode->next;
    }   
    return -1;
}

