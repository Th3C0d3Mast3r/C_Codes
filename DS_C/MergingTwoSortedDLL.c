#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}Node;

typedef struct list{
    Node *head;
    int size;
}List;

void init(List *list)
{
    list->head=NULL;
    list->size=0;
}

void insert(List *list, int x)
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = x;
    newNode->next = NULL;

    Node *temp = list->head;
    if (list->head == NULL)
    {
        list->head = newNode;
        newNode->prev = NULL;
    }
    else
     {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    list->size++;
}

void insertFront(List *list, int x) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->prev = NULL;

    Node *temp = list->head;
   
    if (list->head == NULL)
    {
        list->head = newNode;
        newNode->next = NULL;
    }
    else {
        newNode->next = temp;
        temp->prev = newNode;
        list->head = newNode;
    }
    list->size++;
}

void insertBetween(List *list, int x, int n) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = x;

    Node *temp = list->head;
    if (temp == NULL || n > list->size) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    while (n > 1) {
        temp = temp->next;
        if (temp == NULL) {
            printf("Position out of bounds\n");
            free(newNode);
            return;
        }
        n--;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    list->size++;
}

void insertSorted(List *list, int x) {
    Node *temp = list->head;
    Node *tails = list->head;
    int posCount = 0;

    if (list->head == NULL) {
        insert(list, x);
        return;
    }

    while (tails->next != NULL) {
        tails = tails->next;  // trsver
    }

    if (x > tails->data)
    {
        insert(list, x);
    }
    else if (x < temp->data)
    {
        insertFront(list, x);
    }
    else
    {
        while (temp != NULL && temp->data <= x)
        {
            temp = temp->next;
            posCount++;
        }
        if (temp == NULL)
        {
            insert(list, x);
        }
        else
        {
            insertBetween(list, x, posCount);
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

void mergeLists(List *list1, List *list2)
{
    Node *temp1 = list1->head;
    Node *temp2 = list2->head;

    while (temp2 != NULL) 
    {
        Node *searchNode = list1->head;
        bool exists = false;
        while (searchNode != NULL) 
        {
            if (searchNode->data == temp2->data)
            {
                exists = true;
                break;
            }
            searchNode = searchNode->next;
        }
        if (!exists) 
        {
            insertSorted(list1, temp2->data);
        }
        temp2 = temp2->next;
    }

    printf("Merged list:\n");
    printList(list1);
}


int main()
{
    List list1;
    List list2;
    int inLoop=0;
    
    init(&list1);
    init(&list2);
    
    int data=0;
    char reply;
    
    
    while(inLoop==0)
    {
        printf("Enter the NUMBER IN LIST-1:");
        scanf("%d", &data);
        
        insertSorted(&list1, data);
        
        printf("\nWOULD YOU LIKE TO CONTINUE?");
        scanf(" %c", &reply);
        if(reply=='y' || reply=='Y') inLoop+=0;
        else inLoop++;
    }
    printList(&list1);
    
    inLoop=0;
    while(inLoop==0)
    {
        printf("Enter the NUMBER IN LIST-2:");
        scanf("%d", &data);
        
        insertSorted(&list2, data);
        
        printf("\nWOULD YOU LIKE TO CONTINUE?");
        scanf(" %c", &reply);
        if(reply=='y' || reply=='Y') inLoop+=0;
        else inLoop++;
    }
    printList(&list2);

    
    mergeLists(&list1, &list2);
    return 0;
}
