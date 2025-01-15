#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char c) {
    if (top == SIZE - 1) {
        printf("\nStack Overflow! Exiting the program");
        exit(1);
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("\nStack Underflow!");
        return -1;
    }
    return stack[top--];
}

char peek() {
    return stack[top];
}

bool isEmpty() {
    return top == -1;
}

int priority(char c) {
    if (c == '^' || c == '$')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

int main() {
    char infix[SIZE];
    char currChar;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (int i = 0; infix[i] != '\0'; i++) {
        currChar = infix[i];

        if (isalnum(currChar)) {
            printf("%c", currChar);
        } else if (currChar == '(') {
            push(currChar);
        } else if (currChar == ')') {
            while (peek() != '(') {
                printf("%c", pop());
            }pop();
        } else {
            while (!isEmpty() && priority(peek()) >= priority(currChar)) {
                printf("%c", pop());
            }
            push(currChar);
        }
    }

    while (!isEmpty()) {
        printf("%c", pop());
    }

    printf("\n");
    return 0;
}
