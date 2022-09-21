#include "list.h"

void createList (List *pList) {
    pList->size = 0;
}

int listEmpty(List *pList) {
    return !pList->size;
}

int listFull(List *pList) {
    return pList->size == MAXLIST;
}

void destroyList(List *pList) {
    pList->size = 0;
}

int listSize(List *pList) {
    return pList->size;
}

void insertList(int pos, listEntry e, List *pList) {
    for (int i = pList->size - 1; i >= pos; i--)
        pList->entry[i + 1] = pList->entry[i];
    pList->entry[pos] = e;
    pList->size++;
}

void deleteList(int pos, listEntry *pe, List *pList) {
    *pe = pList->entry[pos];
    for (int i = pos + 1; i <= pList->size - 1; i++)
        pList->entry[i - 1] = pList->entry[i];
    pList->size--;
}

void traverseList(List *pList, void (pVisit)(listEntry)) {
    for (int i = 0; i <= pList->size - 1; i++)
        (*pVisit)(pList->entry[i]);
}

void retrieveList(int pos, listEntry *pe, List *pList) {
    *pe = pList->entry[pos];
}

void replaceList(int pos, listEntry e, List *pList) {
    pList->entry[pos] = e;
}

int sequentialSearch(listEntry e, List *pList) {
    for (int i = 0; i < pList->size; i++)
    {
        if (e == pList->entry[i])
            return i;
    }
    return -1;
}

void insertOrder(listEntry e, List *pList) {
    int i = 0;
    for (; i < pList->size; i++)
        if (e < pList->entry[i]) break;

    insertList(i, e, pList);
}


int binarySearch(listEntry e, List *pList) {
    int bottom = 0, top = pList->size - 1, middle;
    while (top >= bottom)
    {
        middle = top / 2;
        if (pList->entry[middle] == e)
            return middle;

        if (pList->entry[middle] > e)
            top = middle - 1;
        else
            bottom = middle + 1;
    }
    return -1;
}

