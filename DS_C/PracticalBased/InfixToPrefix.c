// INFIX to PREFIX is same as postfix
// THE ONLY DIFFERENCE BEING, we convert to POSTFIX via a REVERSED INFIX
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct s {
    char* arr;
    int totSize;
    int top;
} Stack;

void init(Stack* stack, int s) {
    stack->arr = (char*)malloc(sizeof(char) * s);
    stack->totSize = s;
    stack->top = -1;
}

bool isFull(Stack* stack) {
    return stack->top == stack->totSize - 1;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, char x) {
    if (isFull(stack)) {
        printf("STACK OVERFLOW\n");
        return;
    }
    stack->arr[++(stack->top)] = x;
}

char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("STACK UNDERFLOW\n");
        return -1;
    }
    return stack->arr[(stack->top)--];
}

char peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("STACK UNDERFLOW\n");
        return -1;
    }
    return stack->arr[(stack->top)];
}

int precedence(char ch) {
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/' || ch == '%') return 2;
    if (ch == '+' || ch == '-') return 1;
    return 0;
}

bool isOperator(char ch) {
    return (ch == '*' || ch == '/' || ch == '%' || ch == '+' || ch == '-' || ch == '^');
}

// Reverse the string
void reverse(char* infix) {
    int n = strlen(infix);
    for (int i = 0; i < n / 2; i++) {
        char temp = infix[i];
        infix[i] = infix[n - i - 1];
        infix[n - i - 1] = temp;
    }
}

// Reverse the brackets
void reverseBrackets(char* infix) {
    int len = strlen(infix);
    for (int i = 0; i < len; i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }
}

int main() {
    Stack stack;
    int num;

    printf("Enter STACK Size: ");
    scanf("%d", &num);

    init(&stack, num);

    char infix[100], postfix[100], prefix[100];  // Added prefix array
    int k = 0;

    printf("\nEnter the INFIX EXPRESSION: ");
    scanf("%s", infix);

    // Reverse the infix expression and swap brackets
    reverse(infix);
    reverseBrackets(infix);

    // Convert the reversed expression to postfix
    for (int i = 0; infix[i]; i++) {
        char ch = infix[i];

        if (!isOperator(ch) && ch != '(' && ch != ')') {
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            push(&stack, ch);
        }
        else if (ch == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[k++] = pop(&stack);
            }
            pop(&stack);  // Pop the '('
        }
        else if (isOperator(ch)) {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(ch)) {
                postfix[k++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    while (!isEmpty(&stack)) {
        postfix[k++] = pop(&stack);
    }

    postfix[k] = '\0';  // Null terminate postfix

    // Reverse the postfix to get prefix
    strcpy(prefix, postfix);
    reverse(prefix);

    printf("PREFIX EXPRESSION: %s\n", prefix);

    return 0;
}
