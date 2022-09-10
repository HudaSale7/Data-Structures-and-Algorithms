#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"
#include "global.h"

Stack myStack;
int menu();
void display(queueEntry car);
void stringInput(char str[]);
void reverseDisplay(Queue *pQueue, Stack *pStack);
void pushQueue(queueEntry car);

int main()
{
    Queue myQueue;
    queueEntry car; 
    createQueue(&myQueue);

    while (1)
    {
        int userOption = menu();
        switch (userOption)
        {
        case 1:
            if (queueFull(&myQueue))
                printf("\nQueue is full!");
            else {
                printf("\tEnter the customer name: ");
                stringInput(car.name);
                printf("\tEnter the car id: ");
                scanf("%d", &car.id);
                printf("\tEnter the car model year: ");
                scanf("%d", &car.model);
                append(car, &myQueue);
            }
            printf("\n\t-------------------------\n");
            system("pause");
            system("cls");
            break;
        case 2:
            if (queueEmpty(&myQueue))
                printf("\n there are no Customers waiting!\n");
            else
            {
                serve(&car, &myQueue);
                printf("\tthe car served is:\n");
                printf("\tName: %s\n", car.name);
                printf("\tID: %d\n", car.id);
                printf("\tModel Year: %d\n", car.model);
            }
            printf("\n\t-------------------------\n");
            system("pause");
            system("cls");
            break;
        case 3:
            printf("\t%d Customers are waiting", queueSize(&myQueue));
            printf("\n\t-------------------------\n");
            system("pause");
            system("cls");
            break;
        case 4:
            if (queueEmpty(&myQueue))
                printf("\n there are no Customers waiting!\n");
            else
                traverseQueue(&myQueue, &display);
            system("pause");
            system("cls");
            break;
        case 5:
            if (queueEmpty(&myQueue))
                printf("\n there are no Customers waiting!\n");
            else {
                reverseDisplay(&myQueue, &myStack);
                clearStack(&myStack); } 
            system("pause");
            system("cls");
            break;
        case 6:
        exit(1);
            break;
        default:
        printf("\tWrong Number ! Please Try Again\n");
            break;
        }
    }
    return 0;
}

int menu()
{
    int option;
    printf("  Welcome to our car workshop\n");
    printf("  1. Add a New Customer.\n");
    printf("  2. Serve a Customer.\n");
    printf("  3. How many Customers are waiting?\n");
    printf("  4. Display Customers Information.\n");
    printf("  5. Display Customers information in a \"most-recent\" Order.\n");
    printf("  6. Exit.\n");
    printf("  Your option --> ");
    scanf("%d", &option);
    system("cls");
    return option;
}

void display(queueEntry car) {
    printf("\tName: %s\n", car.name);
    printf("\tID: %d\n", car.id);
    printf("\tModel Year: %d\n", car.model);
    printf("\t---------------------------\n");
}

void stringInput (char str[]) {
    fflush(stdin);
    char ch = 0;
    int i = 0;
    while (1)
    {
        scanf("%c", &ch);
        if (ch  == '\n') break;
        str[i++] = ch;
    }
    str[i] = '\0';
}

void reverseDisplay(Queue *pQueue, Stack *pStack) {
    createStack(pStack);
    traverseQueue(pQueue, &pushQueue);
    traverseStack(pStack, &display);
}

void pushQueue(queueEntry car) {
    push(car, &myStack);
}