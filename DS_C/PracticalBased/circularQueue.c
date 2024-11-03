// Yes, this code was already there, but, this time, I am writing the code with some new things known
// With a relative developed approach-thus, this is the Newer Code for CircularQueue

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue{
    int* arr;
    int front;
    int back;
    int size;                   // non-null present values
    int len;                    // the total elements that can be added to the Queue
} Queue;

void init(Queue* q, int s){
    q->size = 0;
    q->front = -1;
    q->back = -1;
    q->arr = malloc(sizeof(int) * s);           // Fix: sizeof(int) * s (not sizeof(int*))
    q->len = s;                                 // Fix: len should be the passed size 's'
}

bool isEmpty(Queue* q){
    return q->size == 0;
}

bool isFull(Queue* q){
    return q->size == q->len;
}

void enQ(Queue* q, int data){
    if(isFull(q)){
        printf("OVERFLOW-CANNOT ADD\n");
        return;
    }
    if(q->front == -1){
        q->front = 0;
    }
    q->back = (q->back + 1) % q->len;               // q->len being the total array elements that are possible to add
    q->arr[q->back] = data;
    q->size++;                                      // the current present elements
}

int deQ(Queue* q){
    if(q->size == 0){
        printf("UNDERFLOW-QUEUE EMPTY\n");
        return -1;
    }
    int element = q->arr[q->front];
    if(q->front == q->back) {
        q->front = q->back = -1;                    // the whole Queue is reset back to start when only 1 element is there
    } else {
        q->front = (q->front + 1) % q->len;         // making the whole circular and all
    }
    q->size--;
    return element; 
}

void display(Queue* q){
    if(q->size == 0){
        printf("QUEUE IS EMPTY\n");
        return;
    }
    int temp = q->front;
    while(temp != q->back){
        printf("%d | ", q->arr[temp]);
        temp = (temp + 1) % q->len;
    }
    printf("%d\n", q->arr[temp]);                   // the last element that is present
}

int main(){
    Queue q;
    int s;
    printf("Enter TOTAL QUEUE SIZE You Want: ");
    scanf("%d", &s);
    init(&q, s);

    int x;
    while(true){
        printf("\n(1) Enqueue\n(2) Dequeue\n(3) Display Queue\n(4) Exit\n");
        scanf("%d", &x);
        if(x == 1){
            printf("Enter Enqueue Value: ");
            scanf("%d", &x);
            enQ(&q, x);
        }
        else if(x == 2){
            printf("%d\n", deQ(&q));
        }
        else if(x == 3){
            display(&q);
        }
        else break;
    }

    printf("Thank You For Trying the Code! Exiting the Code!\n");
    return 0;
}
