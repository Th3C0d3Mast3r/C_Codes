// NOTE:-  This was the second code that was in the Heap Experiment
// Thus, I have written this code later, that is, on 12th November, 2024
// This is the code for Adding the Value on the Go, and Performing Heap Sort on the Go

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct heaps{
    int* arr;
    int size;
}Heap;

void heapify(Heap* heap); // Forward declaration

void init(Heap* heap, int s){
    heap->arr = (int*)malloc(sizeof(int) * (s + 1)); // Adjusted for 1-based indexing
    heap->size = 0;
}

void insert(Heap* heap, int data){
    heap->arr[++(heap->size)] = data;
    heapify(heap);
}

void swap(Heap* h, int idx1, int idx2){
    int temp = h->arr[idx1];
    h->arr[idx1] = h->arr[idx2];
    h->arr[idx2] = temp;
}

void heapSort(Heap* heap, int index){
    int largest = index;
    int leftChild = index * 2;
    int rightChild = (index * 2) + 1;

    if (leftChild <= heap->size && heap->arr[index] < heap->arr[leftChild]) largest = leftChild;
    if (rightChild <= heap->size && heap->arr[largest] < heap->arr[rightChild]) largest = rightChild;

    if (largest != index){
        swap(heap, index, largest);
        heapSort(heap, largest);
    }
}

void heapify(Heap* heap){
    int lastParentNode = (int)floor((heap->size)/2);
    for(int i = lastParentNode; i >= 1; i--){
        heapSort(heap, i);
    }
}

void displayHeap(Heap* heap){
    int i = 1;  // Adjusted to 1-based indexing
    while (i <= heap->size){
        printf("%d | ", heap->arr[i]);
        i++;
    }
}

void main(){
    Heap heap;
    init(&heap, 100);
    int num = 0;
    printf("Enter the Values for HEAP:-\n");
    while (true){
        printf("VALUE (-1 for termination): ");
        scanf("%d", &num);
        if (num == -1) break;
        insert(&heap, num);
        printf("\nTHE HEAPIFIED HEAP COMES TO BE:- \n");
        displayHeap(&heap);
        printf("\n");
    }

    printf("\nTHE FINAL HEAP COMES TO BE:-\n");
    displayHeap(&heap);
}
