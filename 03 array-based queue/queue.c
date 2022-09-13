#include "queue.h"

void createQueue(Queue *pQueue){
    pQueue->front = 0;
    pQueue->rear = -1;
    pQueue->size = 0;
}

void append(queueEntry e, Queue *pQueue) {
    if (pQueue->rear == MAXQUEUE - 1)
        pQueue->rear = 0;
    else
        pQueue->rear++;
    pQueue->entry[pQueue->rear] = e;
    pQueue->size++;
}

void serve(queueEntry *pElement, Queue *pQueue) {
    *pElement = pQueue->entry[pQueue->front];
    if (pQueue->front == MAXQUEUE - 1)
        pQueue->front = 0;
    else
        pQueue->front++;
    pQueue->size--;
}

int queueFull(Queue *pQueue) {
    return (pQueue->size == MAXQUEUE);
}

int queueEmpty(Queue *pQueue) {
    return !pQueue->size;
}

void clearQueue(Queue *pQueue) {
    pQueue->front = 0;
    pQueue->rear = -1;
    pQueue->size = 0;
}

int queueSize(Queue *pQueue) {
    return pQueue->size;
}

void queueLast(queueEntry *pElement, Queue *pQueue) {
    *pElement = pQueue->entry[pQueue->rear];
}

void traverseQueue(Queue *pQueue, void (*pVisit)(queueEntry)) {
    int index = pQueue->front;
    for (int i = 0; i < pQueue->size; i++)
    {
        (*pVisit)(pQueue->entry[index]);
        index = (index + 1) % MAXQUEUE;
    }
}

void copyQueue(Queue *pQueue, Queue *pCopied) {
    pCopied->front = pQueue->front;
    pCopied->rear = pQueue->rear;
    pCopied->size = pQueue->size;
    int index = pQueue->front;
    for (int i = 0; i < pQueue->size; i++)
    {
        pCopied->entry[index] = pQueue->entry[index];
        index = (index + 1) % MAXQUEUE;
    }
}

