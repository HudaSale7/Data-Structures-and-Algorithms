#define MAXLIST 100
#define listEntry int

typedef struct list
{
    listEntry entry[MAXLIST];
    int size;
} List;

void createList(List *pList);
int listEmpty(List *pList);
int listFull(List *pList);
void destroyList(List *pList);
int listSize(List *pList);
void insertList(int pos, listEntry e, List *pList);
void deleteList(int pos, listEntry *pe, List *pList);
void traverseList(List *pList, void (pVisit)(listEntry));
void retrieveList(int pos, listEntry *pe, List *pList);
void replaceList(int pos, listEntry e, List *pList);
int sequentialSearch(listEntry e, List *pList);
void insertOrder(listEntry e, List *pList);
int binarySearch(listEntry e, List *pList);
