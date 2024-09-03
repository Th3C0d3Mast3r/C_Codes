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
    } else {
        Node *temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    list->size++;
}


// WRITING A FUNCTION TO FIND THE CENTER ELEMENT OF LINKEDLIST
int midDLL(List *list)
{
    Node *fast=list->head;
    Node *slow=list->head;
    
    while(fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow->data;
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
    insert(&list, 10);
    insert(&list, 111);


    printf("Original List:\n");
    printList(&list);


    int middleElement = midDLL(&list);
    printf("Middle element of the list: %d\n", middleElement);

    return 0;
}

// NOTE THIS IS ONE OF THE BASIC AND FREE TO USE LOGIC FOR ALL
// IN MY CODE, I ACTUALLY HAVE THE SIZE OF THE LIST THAT I AM REFERRING TO
// THUS, A BASIC FOR LOOP WITH TRAVERSING TO HALF OF THE LENGTH WOULD ALSO WORK
// SINCE THAT IS EASY-I DID NOT INCLUDE HERE
