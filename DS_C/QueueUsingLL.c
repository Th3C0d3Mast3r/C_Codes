#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}Node;

typedef struct queue{
    Node *root;
    int size;
}Queue;

void init(Queue *q){
    q->root=NULL;
    q->size=0;
}

Node* enQ(Queue *q, int val){
    Node *newNode=(Node*)malloc(sizeof(Node));
    Node *temp=q->root;
    q->size++;
    newNode->data=val;
    newNode->next=NULL;

    if(q->root == NULL){
        newNode->prev=NULL;
        q->root=newNode;
        return q->root;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=newNode;
    newNode->prev=temp;
    newNode->next=NULL;
    return q->root;
}

int deQ(Queue *q){
    // CODE YET TO BE COMPLETED
}