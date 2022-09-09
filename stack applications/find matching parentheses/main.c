#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int takeString();

int main() {
    if (takeString())
        printf("string has correct matching parentheses\n");
    else
        printf("error! string has not correct matching parentheses\n");
    system("pause");
    return 0;
}

int takeString() {
    Stack myStack;
    Stack *pStack = &myStack;
    createStack(pStack);
    stackEntry ch;
    stackEntry open;

    while (1)
    {
        scanf("%c", &ch);
        if (ch == '(' || ch == '[' || ch == '{')
            push(ch, pStack);

        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (stackEmpty(pStack))
                return 0;

            pop(&open, &myStack);
            if (ch - open != 2 && ch - open != 1)
                return 0;
        }
        
        else if (ch == '\n') break;
    }
    if (!stackEmpty(pStack))
        return 0;

    return 1;
}

