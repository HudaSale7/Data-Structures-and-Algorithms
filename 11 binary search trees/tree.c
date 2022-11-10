#include <stdlib.h>
#include "tree.h"

void createTree(Tree *pTree)
{
    pTree->root = NULL;
    pTree->depth = 0;
    pTree->size = 0;
}

int treeFull(Tree *pTree)
{
    return 0;
}

int treeEmpty(Tree *pTree)
{
    return !pTree->root;
}

int treeSize(Tree *pTree)
{
    return pTree->size;
}

int treeDepth(Tree *pTree)
{
    return pTree->depth;
}

void traverseTree(Tree *pTree, void (*pVisit)(treeEntry))
{
    traverseTreeAux(pTree->root, pVisit);
}

void traverseTreeAux(treeNode *pNode, void (*pVisit)(treeEntry))
{
    if (pNode)
    {
        traverseTreeAux(pNode->left, pVisit);
        (*pVisit)(pNode->entry);
        traverseTreeAux(pNode->right, pVisit);
    }
}

void clearTree(Tree *pTree)
{
    clearTreeAux(pTree->root);
    pTree->root = NULL;
    pTree->depth = 0;
    pTree->size = 0;
}

void clearTreeAux(treeNode *pNode)
{
    if (pNode)
    {
        clearTreeAux(pNode->left);
        clearTreeAux(pNode->right);
        free(pNode);
    }
}

void insertTree(Tree *pTree, treeEntry e)
{
    treeNode *curr, *prev;
    treeNode *pNode = (treeNode *)malloc(sizeof(treeNode));
    pNode->entry = e;
    pNode->left = NULL;
    pNode->right = NULL;
    int d = 1;
    if (!pTree->root)
        pTree->root = pNode;
    else
    {
        curr = pTree->root;
        while (curr)
        {
            prev = curr;
            if (curr->entry > e)
                curr = curr->left;
            else
                curr = curr->right;
            d++;
        }
        if (prev->entry > e)
            prev->left = pNode;
        else
            prev->right = pNode;
    }
    pTree->size++;
    if (d > pTree->depth)
        pTree->depth = d;
}

int findElement(Tree *pTree, treeEntry e)
{
    return findElementAux(pTree->root, e);
}

int findElementAux(treeNode *pNode, treeEntry e)
{
    while (pNode)
    {
        if (e == pNode->entry)
            return 1;
        else if (e < pNode->entry)
            pNode = pNode->left;
        else
            pNode = pNode->right;
    }
    return 0;
}

int deleteElement(Tree *pTree, treeEntry e)
{
    treeNode *pNode = pTree->root;
    treeNode *parent = NULL;
    int found = 0;
    while (pNode && !(found = (e == pNode->entry)))
    {
        parent = pNode;
        if (e < pNode->entry)
            pNode = pNode->left;
        else
            pNode = pNode->right;
    }
    if (found)
    {
        if (!parent)
            deleteNode(&pTree->root);
        if (e < parent->entry)
            deleteNode(&parent->left);
        else
            deleteNode(&parent->right);
    }
    return found;
}

void deleteNode(treeNode **pNode)
{
    treeNode *temp = *pNode;
    if (!(*pNode)->left)
        *pNode = (*pNode)->right;

    else if (!(*pNode)->right)
        *pNode = (*pNode)->left;

    else
    {
        temp = (*pNode)->left;
        treeNode *prev;
        if (temp->right)
        {
            while (temp->right) {
                prev = temp;
                temp = temp->right;
            }
            (*pNode)->entry = temp->entry;
            prev->right = temp->left;
        }
        else
        {
            (*pNode)->entry = temp->entry;
            (*pNode)->left = temp->left;
        }
    }
    free(temp);
}
