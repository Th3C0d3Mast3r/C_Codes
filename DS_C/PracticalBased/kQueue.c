// this is some other level code-I required a bit of help from Online Sources to Complete the code
// NOTE:- THIS CODE IS NOT WELL WORKING. SOME CHANGES NEED TO BE MADE TO THIS!
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct kq {
    int *arr;
    int *front;
    int *back;
    int *next;
    int n;                      // Size of the array
    int k;                      // Number of Queues
    int nextFree;               // Next free position in array
} kQueue;

void init(kQueue *kq, int k, int n) {
    kq->k = k;
    kq->n = n;
    kq->arr = (int*) malloc(sizeof(int) * n);
    kq->front = (int*) malloc(sizeof(int) * k);
    kq->back = (int*) malloc(sizeof(int) * k);
    kq->next = (int*) malloc(sizeof(int) * n);

    for (int i = 0; i < k; i++) {
        kq->front[i] = -1;  // Initialize all fronts to -1
        kq->back[i] = -1;   // Initialize all backs to -1
    }

    kq->nextFree = 0;      // All spaces are initially free
    for (int i = 0; i < kq->n - 1; i++) 
        kq->next[i] = i + 1;
    kq->next[kq->n - 1] = -1;  // End of free list
}

bool isEmpty(kQueue *kq, int num) {
    return kq->front[num] == -1;
}

bool isFull(kQueue *kq) {
    return kq->nextFree == -1;        
}

void enQ(kQueue *kq, int num, int data) {
    if (isFull(kq)) {
        printf("OVERFLOW\n");
        return;
    }

    int i = kq->nextFree;  // Get the free index

    if (isEmpty(kq, num)) 
        kq->front[num] = i;
    else 
        kq->next[kq->back[num]] = i;

    kq->next[i] = -1;
    kq->back[num] = i;
    kq->arr[i] = data;

    // Update the next free index to the next available slot
    kq->nextFree = kq->next[i];   // Update nextFree after the insertion
    printf("Next free index: %d\n", kq->nextFree);  // Debugging statement
}

int deQ(kQueue *kq, int num) {
    if (isEmpty(kq, num)) {
        printf("UNDERFLOW\n");
        return INT_MIN;  // Return a special value indicating underflow
    }

    int i = kq->front[num];
    kq->front[num] = kq->next[i];  // Move front to the next element

    if (kq->front[num] == -1) 
        kq->back[num] = -1;  // If queue becomes empty, reset back pointer

    kq->next[i] = kq->nextFree;
    kq->nextFree = i;

    printf("DEQUEUED %d SUCCESSFULLY!\n", kq->arr[i]);
    return kq->arr[i];
}

void displayQ(kQueue *kq, int num) {
    if (isEmpty(kq, num)) {
        printf("QUEUE#%d -> EMPTY\n", num);
        return;
    }

    printf("For QUEUE#%d:- \n", num);
    int i = kq->front[num];
    while (i != -1) {
        printf("%d ", kq->arr[i]);
        i = kq->next[i];
    }
    printf("\n");
}

void displayAllQ(kQueue *kq) {
    for (int i = 0; i < kq->k; i++) {
        displayQ(kq, i);
    }
}

int main() {
    kQueue kQ;
    int num = 0, k = 0;
    printf("How Many Queues You Wish to Make: ");
    scanf("%d", &k);

    printf("\nAnd What is the Total Size of the Array: ");
    scanf("%d", &num);

    init(&kQ, k, num);  // Initialize with total size
    int i = 0;
    while (true) {
        int val = 0;
        printf("Enter Queue Number (-1 to terminate input): ");
        scanf("%d", &i);

        if (i == -1) break;
        printf("Enter Value for Queue#%d: ", i);
        scanf("%d", &val);

        enQ(&kQ, i, val);
    }
    printf("\n\n");
    displayAllQ(&kQ);
    return 0;
}