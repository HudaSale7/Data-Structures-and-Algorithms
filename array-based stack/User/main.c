#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int menu();
void stackTopUser(stackEntry *pe, Stack *ps);
int stackSizeUser(Stack *ps);
void display(stackEntry element);

int main()
{
    Stack myStack;
    Stack copiedStack;
    stackEntry element;
    createStack(&myStack);

    while (1)
    {
        int userOption = menu();
        switch (userOption)
        {
        case 1:
            clearStack(&myStack);
            printf("\n-------------------------\n");
            break;
        case 2:
            printf("\nEnter the element: ");
            fflush(stdin);
            scanf("%c", &element);
            if (stackFull(&myStack))
                printf("\nStack is full!");
            else
                push(element, &myStack);

            printf("\n-------------------------\n");
            break;
        case 3:
            if (stackEmpty(&myStack))
                printf("\nStack is empty!");
            else
            {
                pop(&element, &myStack);
                printf("\nthe element popped is: %c", element);
            }
            printf("\n-------------------------\n");
            break;
        case 4:
            printf("\nthe stack size is: %d", stackSizeUser(&myStack));
            printf("\n-------------------------\n");
            break;
        case 5:
            if (stackEmpty(&myStack))
                printf("\nStack is empty!");
            else
            {
                stackTopUser(&element, &myStack);
                printf("\nthe last element is: %c", element);
            }
            printf("\n-------------------------\n");
            break;
        case 6:
            if (stackEmpty(&myStack))
                printf("\nStack is empty!");
            else
                traverseStack(&myStack, &display);

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
    printf("  1. Clear the stack.\n");
    printf("  2. Read an element then Push it.\n");
    printf("  3. Pop an element then display it.\n");
    printf("  4. What is the stack size?\n");
    printf("  5. Read the last element.\n");
    printf("  6. Display the elements.\n");
    printf("  7. Exit.\n");
    printf("  Your option --> ");
    scanf("%d", &option);
    return option;
}

void stackTopUser(stackEntry *pe, Stack *ps)
{
    pop(pe, ps);
    push(*pe, ps);
}

int stackSizeUser(Stack *ps) {
    char pushedElement[MAXSTACK] = {0};
    char *pindex = pushedElement; 
    while (!stackEmpty(ps))
    {
        pop(pindex, ps);
        pindex++;
    }
    int size = pindex - pushedElement;
    pindex--;
    while (pindex >= pushedElement)
    {
        push(*pindex, ps);
        pindex--;
    }
    return size;
}

void display(stackEntry element) {
    printf("%c\n", element);
}
