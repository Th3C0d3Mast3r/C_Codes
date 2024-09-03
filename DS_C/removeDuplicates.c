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

//WRITING A CODE FOR REMOVING DUPLICATES FROM SORTED LINKED LIST
void removeDuplicates(List *list)
{
    Node *temp = list->head;
    
    while (temp != NULL && temp->next != NULL) 
    {
        if (temp->data == temp->next->data)
        {
            Node *duplicate = temp->next; 
            
            temp->next = duplicate->next;
            if (duplicate->next != NULL)  
            {
                duplicate->next->prev = temp;
            }
            free(duplicate);  // Free the memory of the duplicate node
        }
        else
        {
            temp = temp->next; 
        }
    }
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



int main() 
{
    List list;
    init(&list);

    insert(&list, 1);
    insert(&list, 1);
    insert(&list, 2);
    insert(&list, 3);
    insert(&list, 3);
    insert(&list, 3);
    insert(&list, 10);
    insert(&list, 111);

    printf("Original List:\n");
    printList(&list);

    removeDuplicates(&list);

    printf("List after removing duplicates:\n");
    printList(&list);

    return 0;
}

