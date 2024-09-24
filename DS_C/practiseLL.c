#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
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

Node* insertNode(List *list, int x) {
    Node *temp = list->head;
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        list->size++;
        return list->head;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    list->size++;
    return list->head;
}

Node* insertNodeFront(List *list, int x) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;

    if (list->head == NULL) {
        list->head = newNode;
        newNode->next = NULL;
        list->size++;
        return list->head;
    }

    newNode->next = list->head;
    list->head = newNode;
    list->size++;
    return list->head;
}

void printList(List *list) {
    Node *temp = list->head;
    for (int i = 0; i < list->size; i++) {
        if (i != list->size - 1) {  // Corrected the condition
            printf("%d -> ", temp->data);
        } else {
            printf("%d", temp->data);
        }
        temp = temp->next;  // Move to the next node
    }
    printf("\n");
}

int main() {
    List list;
    init(&list);
    int x = 0;
    char ch;

    while (true) {
        printf("VALUE: ");
        scanf("%d", &x);
        if (x == -1) break;

        printf("(1) Ahead\n(2) Back\n");
        scanf(" %c", &ch);  // Corrected scanf

        if (ch == '1' || ch == 'a' || ch == 'A') {
            insertNode(&list, x);
        } else if (ch == '2' || ch == 'b' || ch == 'B') {  // Fixed the comparison
            insertNodeFront(&list, x);
        } else {
            break;
        }
    }

    printList(&list);

    return 0;
}
