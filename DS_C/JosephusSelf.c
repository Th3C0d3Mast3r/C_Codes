#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct queue
{
    int* arr;
    int front;
    int rear;
    int size;
    int totCap;
};

void init(struct queue *q,int size)
{
    q->size=0;
    q->totCap=size;
    q->arr=(int *)malloc(size*sizeof(int));
    q->front=0;
    q->rear=-1;
}

bool isEmpty(struct queue *q)
{
    return q->size==0;
}

bool isFull(struct queue *q)
{
    return q->size==q->totCap;
}

void enqueue(struct queue* q,int n)
{
    if(isFull(q))
    {
        printf("Queue is full");
    }
    else{
        q->rear = (q->rear + 1) % q->totCap;        // as a circular queue0
        q->arr[q->rear]=n;
        q->size++;
    }  
}

int dequeue(struct queue* q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty.");
        return -1;
    }
    else{
        q->size--;
        int temp=q->arr[q->front];
        q->front = (q->front + 1) % q->totCap;
        return temp;
    }
}

int josephus(struct queue* q, int num, int k){
    int i=k-1;

    while(num!=0){
        while(i!=0){
            enqueue(q, dequeue(q));
            i--;
        }
        dequeue(q);
        i=k-1;
        num--;
    }

    return dequeue(q);
}

void main()
{
    int n,k;
    printf("Let's implement Josephus problem\n");
    printf("Enter the number of people:");
    scanf("%d",&n);     // n => Number of People

    printf("Enter the execution factor:");
    scanf("%d",&k);     // k => Execution factor

    struct queue q;
    init(&q,n);
    int temp=1;
    while(temp!=n+1)
    {
        enqueue(&q,temp);
        temp++;
    }
    int res=josephus(&q,k,n);
    printf("The Last Man Stadning is at %d \n",res-1);
}