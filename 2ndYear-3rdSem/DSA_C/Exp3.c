#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack is full / overflow\n");
        exit(1);
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack is empty / underflow\n");
        exit(1);
    }
    return stack[top--];
}

char stackTop() {
    if (top == -1) {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack[top];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int priority(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '^') {
        return 3;
    }
    return 0;
}

void infixToPostfix(char infix[]) {
    char postfix[MAX];
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top != -1 && stackTop() != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '(' from the stack
        } else if (isOperator(ch)) {
            while (top != -1 && priority(stackTop()) >= priority(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);
}

int main() {
    char infix[MAX];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);
    return 0;
}
