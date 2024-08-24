#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* link;
} Node;

Node* newNode(int data) {
    Node* nn = (Node*)malloc(sizeof(Node));
    nn->data = data;
    nn->link = NULL;
    return nn;
}

void add(Node** head, int data) {
    Node* nn = newNode(data);

    if (*head == NULL) {
        *head = nn;
    } else {
        Node* current = *head;
        while (current->link != NULL) {
            current = current->link;
        }
        current->link = nn;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->link;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice, data;

    do {
        printf("1. Insert data\n");
        printf("2. Print list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                add(&head, data);
                break;
            case 2:
                printList(head);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}