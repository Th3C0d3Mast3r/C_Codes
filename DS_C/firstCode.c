// this is a code for PREFIX to POSTFIX conversion

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct stack {
    int size;
    char *arr;
    int top;
} Stack;

Stack *s;

void init(int size) {
    s->size = size;
    s->arr = (char *)malloc(sizeof(char) * s->size);
    s->top = -1;
}

bool isEmpty() {
    return s->top == -1;
}

bool isFull() {
    return s->top == s->size - 1;
}

void push(char c) {
    if (isFull()) {
        printf("STACK OVERFLOW\n");
    } else {
        s->arr[++(s->top)] = c;
    }
}

char pop() {
    if (isEmpty()) {
        printf("STACK UNDERFLOW\n");
        return '\0';
    } else {
        return s->arr[(s->top)--];
    }
}

char peek() {
    if (isEmpty()) {
        printf("STACK UNDERFLOW\n");
        return '\0';
    } else {
        return s->arr[s->top];
    }
}

// Function to check if a character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '~';
}

int preced(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0; // for parenthesis and other characters
}

int main() {
    s = (Stack *)malloc(sizeof(Stack));
    int size = 20; // initial size of the stack
    init(size);

    char input[20];

    printf("ENTER THE INFIX:\n");
    scanf("%[^\n]s", input);

    printf("\n\nTHE CONVERTED POSTFIX IS:\n");

    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        char c = input[i];
        if (!isOperator(c) && c != '(' && c != ')') {
            printf("%c ", c); // Directly print operands
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                printf("%c ", pop());
            }
            pop(); // pop the '('
        } else {
            while (!isEmpty() && preced(peek()) >= preced(c)) {
                printf("%c ", pop());
            }
            push(c);
        }
    }

    return 0;
}
