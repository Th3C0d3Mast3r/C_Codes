#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    return stack->top == stack->totSize - 1;  // Corrected this condition
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
        return -1;  // Return -1 on underflow
    }
    return stack->arr[(stack->top)--];
}

char peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("STACK UNDERFLOW\n");
        return -1;  // Return -1 if the stack is empty
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

int main() {
    Stack stack;
    int num;

    printf("Enter STACK Size: ");
    scanf("%d", &num);

    init(&stack, num);

    char infix[100], postfix[100];
    int k = 0;  // Index for postfix expression

    printf("\nEnter the INFIX EXPRESSION: ");
    scanf("%s", infix);

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

    postfix[k] = '\0';  // Null terminate the postfix expression

    printf("POSTFIX EXPRESSION: %s\n", postfix);

    return 0;
}
