#define treeEntry int

typedef struct treenode
{
    treeEntry entry;
    struct treenode *left;
    struct treenode *right;
}treeNode;

typedef struct tree
{
    treeNode *root;
    int size;
    int depth;
}Tree;

void createTree(Tree *pTree);
void insertTree(Tree *pTree, treeEntry e);
void traverseTree(Tree *pTree, void (*pVisit)(treeEntry));
void traverseTreeAux(treeNode *pNode, void (*pVisit)(treeEntry));
void clearTree(Tree *pTree);
void clearTreeAux(treeNode *pNode);
int treeFull(Tree *pTree);
int treeEmpty(Tree *pTree);
int treeSize(Tree *pTree);
int treeDepth(Tree *pTree);
int findElement(Tree *pTree, treeEntry e);
int findElementAux(treeNode *pNode, treeEntry e);
int deleteElement(Tree *pTree, treeEntry e);
void deleteNode(treeNode **pNode);
