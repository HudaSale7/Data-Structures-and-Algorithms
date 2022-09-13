#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int menu();
void display(queueEntry element);

int main()
{
    Queue myQueue;
    Queue copiedStack;
    queueEntry element;
    createQueue(&myQueue);

    while (1)
    {
        int userOption = menu();
        switch (userOption)
        {
        case 1:
            clearQueue(&myQueue);
            printf("\n-------------------------\n");
            break;
        case 2:
            printf("\nEnter the element: ");
            fflush(stdin);
            scanf("%c", &element);
            if (queueFull(&myQueue))
                printf("\nQueue is full!");
            else
                append(element, &myQueue);

            printf("\n-------------------------\n");
            break;
        case 3:
            if (queueEmpty(&myQueue))
                printf("\nQueue is empty!");
            else
            {
                serve(&element, &myQueue);
                printf("\nthe element served is: %c", element);
            }
            printf("\n-------------------------\n");
            break;
        case 4:
            printf("\nthe Queue size is: %d", queueSize(&myQueue));
            printf("\n-------------------------\n");
            break;
        case 5:
            if (queueEmpty(&myQueue))
                printf("\nQueue is empty!");
            else
            {
                queueLast(&element, &myQueue);
                printf("\nthe last element is: %c", element);
            }
            printf("\n-------------------------\n");
            break;
        case 6:
            if (queueEmpty(&myQueue))
                printf("\nQueue is empty!");
            else
                traverseQueue(&myQueue, &display);

            printf("\n-------------------------\n");
            break;
        case 7:
            exit(1);
        default:
            break;
        }
    }
    return 0;
}

int menu()
{
    int option;
    printf("  1. Clear the queue.\n");
    printf("  2. Read an element then append it.\n");
    printf("  3. serve an element then display it.\n");
    printf("  4. What is the queue size?\n");
    printf("  5. Read the last element.\n");
    printf("  6. Display the elements.\n");
    printf("  7. Exit.\n");
    printf("  Your option --> ");
    scanf("%d", &option);
    return option;
}

void display(queueEntry element) {
    printf("%c\n", element);
}
