#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 


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


void insert(List *list, int x) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;

    if (list->head == NULL) {
        newNode->prev = NULL;
        list->head = newNode;
    } 
    else {
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


bool LLPalin(List *list) 
{
    if (list->size == 0)
    {
        return false; 
    }
    
    Node *front = list->head;
    Node *back = list->head;
    
    
    while (back->next != NULL) {
        back = back->next;
    }


    while (front != back && front->prev != back) 
    { 
        if (front->data != back->data) 
        {
            return false;  
        }
        front = front->next;  
        back = back->prev;    
    }

    return true;  
}

void printList(List *list) 
{
    Node *temp = list->head;
    printf("List: ");
    
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() 
{
    List list;
    init(&list);

    insert(&list, 1);
    insert(&list, 2);
    insert(&list, 3);
    insert(&list, 2);
    insert(&list, 1);

    printf("Original List:\n");
    printList(&list);

    if (LLPalin(&list)) {
        printf("The list is palindromic.\n");
    } else {
        printf("The list is not palindromic.\n");
    }

    return 0;
}
