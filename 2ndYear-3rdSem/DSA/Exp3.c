#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define max 100

char stack[max];
int top = -1;

void push(char c)
{
    if (top == max - 1)
    {
        printf("Stack is full / overflow\n");
        exit(1);
    }
    else
    {
        stack[++top] = c; // Increment top before assignment
    }
}

char pop()
{
    if (top == -1)
    {
        printf("Stack is empty / underflow\n");
        exit(1);
    }
    else
    {
        return stack[top--]; // Return and decrement top
    }
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int priority(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0; // Non-operators have lowest priority
    }
}

void infixToPostfix(char infix[])
{
    char postfix[max];
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];

        if (isalnum(ch))
        { // Operand: copy to postfix expression
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch); // Opening parenthesis: push onto stack
        }
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            pop(); // Remove '(' from the stack
        }
        else if (isOperator(ch))
        {
            while (top != -1 && priority(stack[top]) >= priority(ch))
            {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression

    printf("Postfix expression: %s\n", postfix);
}

int main()
{
    char infix[max];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);
    return 0;
}
