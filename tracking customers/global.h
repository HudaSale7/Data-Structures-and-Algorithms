#ifndef GLOBAL_H
#define GLOBAL_H

typedef struct elementtype
{
    char name[20];
    int id;
    int model;
} elementType;

#define MAXELEMENTS 100

typedef elementType stackEntry;
#define MAXSTACK MAXELEMENTS

typedef elementType queueEntry;
#define MAXQUEUE MAXELEMENTS

#endif