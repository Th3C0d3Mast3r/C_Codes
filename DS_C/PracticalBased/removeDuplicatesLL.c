#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void add(List* list, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    list->size++;

    if (list->head == NULL) {
        list->head = newNode;
        return;
    }

    Node* temp = list->head;
    Node* last = NULL;  
    while (temp != NULL)
    {
        if (temp->data == val) return; // Avoid duplicates
        last = temp; 
        temp = temp->next;
    }
    last->next = newNode;
}

void display(List* list){
    Node* temp=list->head;
    while(temp!=NULL){
        printf("%d -> ", temp->data);
        temp=temp->next;
    }
    printf("NULL");
}

void main(){
    List list;
    init(&list);
    int num;
    while(true){
        printf("Enter Value (-1 to terminate):- ");
        scanf("%d", &num);
        if(num==-1) break;
        add(&list, num);
        display(&list);
        printf("\n");
    }
}