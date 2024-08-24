#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct queue {
    int size;
    int *arr;
    int front, back;
} Queue;

// Function to initialize a queue
void init(int size, Queue *q) {
    q->size = size;
    q->arr = (int *)malloc(sizeof(int) * q->size);
    q->front = -1;
    q->back = -1;
    printf("Queue initialized with size %d\n", size); //to check that is it even initialized or no
}

// Check if the queue is full
bool isFull(Queue *q) {
    return ((q->back + 1) % q->size == q->front);
}

// Check if the queue is empty
bool isEmpty(Queue *q) {
    return (q->front == -1);
}

// Enqueue operation
void enQ(Queue *q, int x) {
    if (isFull(q)) {
        printf("OVERFLOW\n");
    } else {
        if (q->front == -1) {
            q->front = 0; // Initialize front when first element is enqueued
        }
        q->back = (q->back + 1) % q->size;
        q->arr[q->back] = x;
    }
}

// Dequeue operation
int deQ(Queue *q) {
    if (isEmpty(q)) {
        printf("UNDERFLOW\n");
        return -1; // Indicate an error
    } else {
        int data = q->arr[q->front];
        if (q->front == q->back) {
            q->front = q->back = -1; // Queue becomes empty
        } else {
            q->front = (q->front + 1) % q->size;
        }
        return data;
    }
}

int frontPeek(Queue *q) {
    return q->arr[q->front];
}

int backPeek(Queue *q) {
    return q->arr[q->back];
}

void sortingAlgo(Queue *q) {
    Queue h1, h2, h3;
    int s = 10; // Ensure sufficient size for holding queues

    init(s, &h1);
    init(s, &h2);
    init(s, &h3);

    int next = 1;
    while (next <= 9)
    {
        int temp = deQ(q);
        if (temp == -1) {
            break;
        }
        if (temp == next) {
            printf("%d ", temp);
            next++;
        } else {
            if (isEmpty(&h1) || temp > backPeek(&h1)) {
                enQ(&h1, temp);
            } else if (isEmpty(&h2) || temp > backPeek(&h2)) {
                enQ(&h2, temp);
            } else if (isEmpty(&h3) || temp > backPeek(&h3)) {
                enQ(&h3, temp);
            } else {
                printf("ERROR: No suitable track for car %d\n", temp);
                break;
            }
        }

        while ((!isEmpty(&h1) && frontPeek(&h1) == next) ||
               (!isEmpty(&h2) && frontPeek(&h2) == next) ||
               (!isEmpty(&h3) && frontPeek(&h3) == next))
                {
                    if (!isEmpty(&h1) && frontPeek(&h1) == next) {
                        printf("%d ", deQ(&h1));
                        next++;
                    }
                    if (!isEmpty(&h2) && frontPeek(&h2) == next) {
                        printf("%d ", deQ(&h2));
                        next++;
                    }
                    if (!isEmpty(&h3) && frontPeek(&h3) == next) {
                        printf("%d ", deQ(&h3));
                        next++;
                    }
                }
        }
    printf("\n");

    // Free the allocated memory for holding queues
    free(h1.arr);
    free(h2.arr);
    free(h3.arr);
}

int main() {
    int size = 9;
    Queue iq;
    init(size, &iq);

    enQ(&iq, 3);
    enQ(&iq, 6);
    enQ(&iq, 9);
    enQ(&iq, 2);
    enQ(&iq, 4);
    enQ(&iq, 7);
    enQ(&iq, 1);
    enQ(&iq, 8);
    enQ(&iq, 5);

    sortingAlgo(&iq);

    // Free the allocated memory for the main queue
    free(iq.arr);

    return 0;
}
