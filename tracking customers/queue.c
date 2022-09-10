#include "queue.h"
#include <stdlib.h>

void createQueue(Queue *pQueue){
    pQueue->front = NULL;
    pQueue->rear = NULL;
    pQueue->size = 0;
}

void append(queueEntry e, Queue *pQueue) {
    queueNode *pNode = (queueNode*) malloc(sizeof(queueNode));
    pNode->entry = e;
    if (!pQueue->front)
        pQueue->front = pNode;
    else
        pQueue->rear->next = pNode;
    pQueue->rear = pNode;
    pNode->next = NULL;
    pQueue->size++;
}

void serve(queueEntry *pElement, Queue *pQueue) {
    queueNode *pNode = pQueue->front;
    *pElement = pNode->entry;
    pQueue->front = pQueue->front->next;
    if (!pQueue->front)
        pQueue->rear = NULL;
    free(pNode);
    pQueue->size--;
}


int queueFull(Queue *pQueue) {
    return 0;
}

int queueEmpty(Queue *pQueue) {
    return !pQueue->front;
}

void clearQueue(Queue *pQueue) {
    queueNode *pNode;
    while (pQueue->front)
    {
        pNode = pQueue->front;
        pQueue->front = pQueue->front->next;
        free(pNode);
    }
    pQueue->rear = NULL;
    pQueue->size = 0;
}

int queueSize(Queue *pQueue) {
    return pQueue->size;
}

void queueLast(queueEntry *pElement, Queue *pQueue) {
    *pElement = pQueue->rear->entry;
}

void traverseQueue(Queue *pQueue, void (*pVisit)(queueEntry)) {
    queueNode *pNode = pQueue->front;
    while (pNode)
    {
        (*pVisit)(pNode->entry);
        pNode = pNode->next;
    }
}

void copyQueue(Queue *pQueue, Queue *pCopied) {
    clearQueue(pCopied);
    queueNode *pNode = pQueue->front;
    queueNode *pNodeCopied = (queueNode *)malloc(sizeof(queueNode));
    pCopied->front = pNodeCopied;
    pCopied->size = 1;
    pNodeCopied->entry = pNode->entry;
    pNode = pNode->next;
    while (pNode)
    {
        pNodeCopied->next = (queueNode *)malloc(sizeof(queueNode));
        pNodeCopied = pNodeCopied->next;
        pNodeCopied->entry = pNode->entry;
        pNode = pNode->next;
        pCopied->size++;
    }
    pCopied->rear = pNodeCopied;
    pNodeCopied->next = NULL;
}

