#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} Node;

typedef struct list {
    Node *head;
    int size;
} List;

void init(List *list) {
    list->head = NULL;
    list->size = 0;
}

void insert(List *list, int x) 
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;

    if (list->head == NULL) 
    {
        newNode->prev = NULL;
        list->head = newNode;
    } 
    else
    {
        Node *temp = list->head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    list->size++;
}

void rotateLL(List *list, int k) {
    if (list->head == NULL || k <= 0 || k >= list->size)           // the edge case was shown as a bug fix via AI
    {
        return;
    }

    int newK = list->size - (k % list->size); 

    Node *temp = list->head;
    for (int i = 1; i < newK; i++)
    { 
        temp = temp->next;
    }

    Node *newHead = temp->next;
    newHead->prev = NULL;
    temp->next = NULL;  

    Node *current = newHead;
    while (current->next != NULL) 
    {
        current = current->next;  
    }
    current->next = list->head; 
    list->head->prev = current;
    list->head = newHead;
}

void printList(List *list)
{
    Node *temp = list->head;
    printf("List: ");
    
    while (temp != NULL) 
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    List list;
    init(&list);

    insert(&list, 1);
    insert(&list, 2);
    insert(&list, 3);
    insert(&list, 4);
    insert(&list, 5);

    printf("Original List:\n");
    printList(&list);

    rotateLL(&list, 2);

    printf("List after rotation:\n");
    printList(&list);

    return 0;
}
