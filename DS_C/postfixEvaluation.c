/* 
HOW TO SOLVE POSTFIX:-
- Read the sting LEFT to RIGHT  (normal english way-incrementing for loop)
- If you see a NUMBER, then PUSH that in the stack (thus, postfix evaluation == operand stack)
- When u see operator- perform:-    int num2=pop();
                                    int num1=pop();
                                    push(num1 <operator> num2);
- At end, a single NUMBER(positive or negative, doesnt matter) should be in stack
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

typedef struct stack {
    int size;
    int *arr;  // Pointer to stack array
    int top;
} Stack;

Stack *s;

void init(int sizz) {
    s->size = sizz;
    s->arr = (int *)malloc(sizeof(int) * s->size);
    s->top = -1;
}

bool isEmpty() {
    return s->top == -1;
}

bool isFull() {
    return s->top == s->size - 1;
}

void push(int x) {
    if (isFull()) {
        printf("STACK OVERFLOW\n");
    } else {
        s->arr[++s->top] = x;  // Increment top and push value
    }
}

int pop() {
    if (!isEmpty()) {
        return s->arr[s->top--];  // Return value and decrement top
    } else {
        printf("STACK UNDERFLOW\n");
        return -1;
    }
}

int peek() {
    if (!isEmpty()) {
        return s->arr[s->top];
    } else {
        printf("STACK UNDERFLOW\n");
        return -1;
    }
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '~';
}

int performAdd(int num2, int num1) {
    return num1 + num2;
}

int performSub(int num2, int num1) {
    return num1 - num2;
}

int performMulti(int num2, int num1) {
    return num1 * num2;
}

int performDiv(int num2, int num1) {
    if (num2 == 0) {
        printf("ERROR: Division by zero\n");
        exit(1);
    }
    return num1 / num2;
}

int main() {
    s = (Stack *)malloc(sizeof(Stack));
    init(20);

    char str[20];

    printf("ENTER THE POSTFIX TO BE EVALUATED: ");
    scanf("%[^\n]s", str);
    int len = strlen(str);

    printf("THE FINAL EVALUATION COMES TO: ");

    for (int i = 0; i < len; i++) {
        if (isdigit(str[i])) {  // Check if the character is a digit
            int x = str[i] - '0';  // Convert char to int
            push(x);
        } else if (isOperator(str[i])) {
            int num2 = pop();
            int num1 = pop();
            switch (str[i]) {  // Use switch-case for cleaner code
                case '+':
                    push(performAdd(num2, num1));
                    break;
                case '-':
                    push(performSub(num2, num1));
                    break;
                case '*':
                    push(performMulti(num2, num1));
                    break;
                case '/':
                    push(performDiv(num2, num1));
                    break;
            }
        }
    }
    while (!isEmpty()) {
        printf("%d ", pop());
    }
    printf("\n");

    free(s->arr); 
    free(s);      
    return 0;
}
