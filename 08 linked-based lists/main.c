#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int menu();

void display(listEntry element);

int main()
{
    List myList;
    listEntry element;
    int position;
    createList(&myList);

    while (1)
    {
        int userOption = menu();
        switch (userOption)
        {
        case 1:
            destroyList(&myList);
            printf("\n-------------------------\n");
            break;
        case 2:
            printf("\nEnter the element: ");
            fflush(stdin);
            scanf("%c", &element);
            printf("\nEnter the position: ");
            fflush(stdin);
            scanf("%d", &position);
            if (listFull(&myList))
                printf("\nList is full!");
            else
                insertList(position, element, &myList);

            printf("\n-------------------------\n");
            break;
        case 3:
            if (listEmpty(&myList))
                printf("\nList is empty!");
            else
            {
                printf("\nEnter the position: ");
                fflush(stdin);
                scanf("%d", &position);
                deleteList(position, &element, &myList);
                printf("\nthe element deleted is: %c", element);
            }
            printf("\n-------------------------\n");
            break;
        case 4:
            printf("\nthe List size is: %d", listSize(&myList));
            printf("\n-------------------------\n");
            break;
        case 5:
            if (listEmpty(&myList))
                printf("\nList is empty!");
            else
            {
                printf("\nEnter the position: ");
                fflush(stdin);
                scanf("%d", &position);
                retrieveList(position, &element, &myList);
                printf("\nthe element is: %c", element);
            }
            printf("\n-------------------------\n");
            break;
        case 6:
            if (listEmpty(&myList))
                printf("\nList is empty!");
            else
                traverseList(&myList, &display);

            printf("\n-------------------------\n");
            break;
        case 7:
            if (listEmpty(&myList))
                printf("\nList is empty!");
            else
                printf("\nEnter the element: ");
            fflush(stdin);
            scanf("%c", &element);
            printf("\nEnter the position: ");
            fflush(stdin);
            scanf("%d", &position);
            replaceList(position, element, &myList);
            printf("\n-------------------------\n");
            break;
        case 8:
            if (listEmpty(&myList))
                printf("\nList is empty!");
            else
            {
                printf("\nEnter the element: ");
                fflush(stdin);
                scanf("%c", &element);
                position = sequentialSearch(element, &myList);
                printf("\nthe position of the element is: %d", position);
                printf("\n-------------------------\n");
            }
        default:
            break;
        }
    }
    return 0;
}

int menu()
{
    int option;
    printf("  1. Clear the List.\n");
    printf("  2. insert to the list.\n");
    printf("  3. delete from the list.\n");
    printf("  4. What is the List size?\n");
    printf("  5. view element.\n");
    printf("  6. Display the elements.\n");
    printf("  7. replace element.\n");
    printf("  8. search for element.\n");
    printf("  Your option --> ");
    scanf("%d", &option);
    return option;
}

void display(listEntry element)
{
    printf("%c\n", element);
}