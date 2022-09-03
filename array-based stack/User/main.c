#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int menu();

int main()
{
    Stack myStack;
    stackEntry element;
    createStack(&myStack);

    while (1)
    {
        int userOption = menu();
        switch (userOption)
        {
        case 1:
            
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:
            exit(1);
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
    printf("  1. Clear the stack.\n");
    printf("  2. Read an element then Push it.\n");
    printf("  3. Pop an element then display it.\n");
    printf("  4. What is the stack size?\n");
    printf("  5. Read the last element.\n");
    printf("  6. Exit.\n");
    printf("  Your option --> ");
    scanf("%d", &option);
    system("cls");
    return option;
}