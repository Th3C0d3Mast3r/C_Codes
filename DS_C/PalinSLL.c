#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node* next;
} Node;

typedef struct list {
    Node *head;
    int size;
} List;

void init(List *list) {
    list->head = NULL;
    list->size = 0;
}

void insert(List *list, char x) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

void printList(List *list) {
    Node *current = list->head;
    while (current != NULL) {
        printf(" %c", current->data); // Corrected this line
        current = current->next; // Move to the next node
        if (current != NULL)
            printf(" ->");
    }
    printf("\n");
}

int isPalindrome(List *list) {
    char arr[list->size];
    Node *temp = list->head;
    int top = 0;

    while (temp != NULL) {
        arr[top++] = temp->data;
        temp = temp->next;
    }

    for (int i = 0; i < list->size / 2; i++) {
        if (arr[i] != arr[list->size - 1 - i]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Is a palindrome
}

void freeList(List *list) {
    Node *current = list->head;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    List list;
    init(&list);

    insert(&list, 'A');
    insert(&list, 'B');
    insert(&list, 'B');
    insert(&list, 'A');

    printList(&list);

    if (isPalindrome(&list)) {
        printf("PALINDROME\n");
    } else {
        printf("NOT PALINDROME\n");
    }

    freeList(&list); // Clean up memory
    return 0;
}
