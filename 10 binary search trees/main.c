#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

void display(treeEntry element);
int menu();

int main()
{
    Tree myTree;
    treeEntry element;
    createTree(&myTree);
    while (1)
    {
        int userOption = menu();
        switch (userOption)
        {
        case 1:
            clearTree(&myTree);
            printf("\n-------------------------\n");
            break;
        case 2:
            printf("\nEnter the element: ");
            fflush(stdin);
            scanf("%d", &element);

            if (treeFull(&myTree))
                printf("\nTree is full!");
            else
                insertTree(&myTree, element);

            printf("\n-------------------------\n");
            break;

        case 3:
            printf("\nthe Tree size is: %d", treeSize(&myTree));
            printf("\n-------------------------\n");
            break;

        case 4:
            if (treeEmpty(&myTree))
                printf("\nTree is empty!");
            else
                traverseTree(&myTree, &display);

            printf("\n-------------------------\n");
            break;
        case 5:
            printf("\nthe Tree depth is: %d", treeDepth(&myTree));
            printf("\n-------------------------\n");
            break;
        case 6:
            if (treeEmpty(&myTree))
                printf("\nTree is empty!");
            else
            {
                printf("\nEnter the element: ");
                fflush(stdin);
                scanf("%d", &element);
                if (findElement(&myTree, element))
                    printf("\nelement was found ");
                else
                    printf("\nelement was not found ");
            }
            printf("\n-------------------------\n");
            break;
        case 7:
            if (treeEmpty(&myTree))
                printf("\nTree is empty!");
            else
            {
                printf("\nEnter the element: ");
                fflush(stdin);
                scanf("%d", &element);
                if (deleteElement(&myTree, element))
                    printf("\nelement was deleted ");
                else
                    printf("\nelement was not found ");
            }
            printf("\n-------------------------\n");
            break;
        default:
            break;
        }
    }
    return 0;
}

int menu()
{
    int option;
    printf("  1. Clear the Tree.\n");
    printf("  2. insert to the Tree.\n");
    printf("  3. What is the Tree size?\n");
    printf("  4. display the Tree.\n");
    printf("  5. What is the tree depth.\n");
    printf("  6. Find element.\n");
    printf("  7. delete element.\n");

    printf("  Your option --> ");
    scanf("%d", &option);
    return option;
}

void display(treeEntry element)
{
    printf("%d\n", element);
}
