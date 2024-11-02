// PALINDROME CHECKER WITHOUT USING ANY EXTRA SPACE OR WHATSOEVER!

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

// Helper function to reverse the second half of the list
Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to check if the linked list is a palindrome
bool isPalin(List* list) {
    if (list->head == NULL || list->head->next == NULL) {
        return true;  // Empty list or single node is always a palindrome
    }

    Node* slow = list->head;
    Node* fast = list->head;

    // Find the middle of the list using slow and fast pointers
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list
    Node* secondHalf = reverse(slow);

    // Compare the first half with the reversed second half
    Node* firstHalf = list->head;
    Node* temp = secondHalf;

    bool isPalin = true;
    while (temp != NULL) {
        if (firstHalf->data != temp->data) {
            isPalin = false;
            break;
        }
        firstHalf = firstHalf->next;
        temp = temp->next;
    }

    // Restore the list (optional but good practice)
    reverse(secondHalf);

    return isPalin;
}

// Function to display the linked list
void display(List* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Driver function
int main() {
    List myList;
    init(&myList);
    int val;
    while(true){
        printf("Enter the Value (-1 to Terminate Entering): ");
        scanf("%d", &val);
        if(val==-1) break;
        add(&myList, val);
    }

    printf("\n\nOriginal List: ");
    display(&myList);

    if (isPalin(&myList)) {
        printf("PALINDROME\n");
    } else {
        printf("NOT A PALINDROME\n");
    }

    return 0;
}
