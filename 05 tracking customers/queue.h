#include "global.h"

typedef struct node
{
    queueEntry entry;
    struct node *next;
} queueNode;

typedef struct queue
{
    queueNode *front;
    queueNode *rear;
    int size;
} Queue;


void createQueue(Queue *pQueue);

void append(queueEntry e, Queue *pQueue);

void serve(queueEntry *pElement, Queue *pQueue);

int queueFull(Queue *pQueue);

int queueEmpty(Queue *pQueue);

void clearQueue(Queue *pQueue);

int queueSize(Queue *pQueue);

void queueTop(Queue *pQueue);

void traverseQueue(Queue *pQueue, void (*pVisit)(queueEntry));

void copyQueue(Queue *pQueue, Queue *pCopied);

void queueLast(queueEntry *pElement, Queue *pQueue);
