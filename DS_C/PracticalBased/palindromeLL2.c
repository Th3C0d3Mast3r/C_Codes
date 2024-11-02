// THIS IS THE CODE WHERE WE CAN USE EXTRA SPACE FOR PALINDROME CHECK
// THE LOGIC IS SAME-WE CREATE A STACK AND THEN, WHILE POPPING IT, THE NUMBERS COME REVERSED
// IF THE WHOLE TRAVERSAL MATCHES, THEN IT IS PALINDROME!

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

// FIRST I HAVE ALL RELATED TO STACK
typedef struct stack {
    int size;
    int *arr;  // Pointer to stack array
    int top;
} Stack;

void initStack(Stack* stack, int sizz) {
    stack->size = sizz;
    stack->arr = (int *)malloc(sizeof(int) * sizz);
    stack->top = -1;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

bool isFull(Stack* stack) {
    return stack->top == stack->size - 1;
}

void push(Stack* stack, int x) {
    if (isFull(stack)) {
        printf("STACK OVERFLOW\n");
    } else {
        stack->arr[++stack->top] = x;  // Increment top and push value
    }
}

int pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top--];  // Return value and decrement top
    } else {
        printf("STACK UNDERFLOW\n");
        return -1;
    }
}

int peek(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top];
    } else {
        printf("STACK UNDERFLOW\n");
        return -1;
    }
}

// NOW ALL THE THINGS RELATED TO LINKEDLIST
typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct list {
    Node* head;
    int size;
} List;

// Initialize the list
void init(List* list) {
    list->head = NULL;
    list->size = 0;
}

Node* add(List* list, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    list->size++;

    if (list->head == NULL) {
        list->head = newNode;
        return newNode;
    }

    Node* temp = list->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    return newNode;
}

void displayLL(List* list){
    Node* temp=list->head;
    while(temp->next!=NULL){
        printf("%d -> ", temp->data);
        temp=temp->next;
    }
    printf("%d", temp->data);
}


int main(){
    List list;
    init(&list);

   int num;
    while(true) {
        printf("Enter Value (-1 to Terminate Input):- ");
        scanf("%d", &num);
        if(num == -1) break;  // Break on input -1
        add(&list, num);
    }
    printf("Entered List is:- ");
    displayLL(&list);
    printf("\n\n");

    Stack stack;
    initStack(&stack, list.size);

    Node *temp = list.head;
    while(temp != NULL) { 
        push(&stack, temp->data);
        temp = temp->next;
    }
    List list2;
    init(&list2);

    while(isEmpty(&stack)){
        add(&list2, pop(&stack));
    }

    Node *firstList=list.head;
    Node *secondList=list2.head;
    while(secondList!=NULL && firstList!=NULL){
        if(secondList->data == firstList->data){
            secondList=secondList->next;
            firstList=firstList->next;
        }
        else{
            printf("NOT PALINDROME");
            return 1;
        }
    }
    printf("PALINDROME");
    return 0;
}