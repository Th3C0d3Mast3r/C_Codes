/*
    The Following code is NOT WRITTEN by me
    It is a code written by my fellow batchmate Mayur.
*/


#include<stdlib.h>
#include<stdio.h>
struct node{
    int val;
    struct node* next;
};
struct node* front = NULL;
struct node* rear = NULL;

struct node* createNode(int val){
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p -> val = val;
    p -> next = NULL;
    return p;
}

void Enqueue(int x){
    struct node* p = createNode(x);
    if(front == NULL && rear == NULL){
        front = p;
        rear = p;
    }
    else{
        rear -> next = p;
        rear = rear -> next;
        rear->next = front;
    }
}


int Dequeue(){
    if(front == NULL ){
    printf("queue is empty");
    }
    else{
        int x;
        if(front == rear)
        {
            x = front -> val;
            free(front);
            front = NULL;
            rear = NULL;
            return x;
        }
        else{
            struct node* p = front;
            x = front -> val;
            front = front -> next;
            rear->next = front;
            free(p);
            return x;
        }
    }
}


void josephus(int n, int k){
    int i = k-1;
    while(n!= 1){
        while(i!=0){
            int x = Dequeue();
            Enqueue(x);
            i--;
        }
        i = k-1;
        printf("member eleminated is: %d \n", Dequeue());
        n--;
    }
    printf("\nWinner is: %d \n",Dequeue());
}


void main(){
    int n,k;
    printf("Enter the number of members:");
    scanf("%d",&n);
    printf("Enter the elemination interval:");
    scanf("%d",&k);

    for(int i = 0; i < n; i ++){
        Enqueue(i+1);
    }
    josephus(n,k);
}