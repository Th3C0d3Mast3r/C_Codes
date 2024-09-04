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
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = x;
    newNode->next = NULL;

    Node *temp = list->head;
    if (list->head == NULL) {
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

int main()
{
    List list;
    char ch;
    int data = 0;
    int inLoop = 0;
    init(&list);

    while (inLoop == 0)
    {
        printf("Do You Want to Insert in List? Y or N:  ");
        scanf(" %c", &ch); 

        if (ch == 'Y' || ch == 'y' || ch == '1') {
            printf("Enter the Data:- ");
            scanf("%d", &data);
            insertSorted(&list, data);
            printf("\n");
            printList(&list);
        }
        else {
            printf("LEAVING CODE! THANK YOU\n\n\n");
            inLoop++;
        }
    }
    printList(&list);
    return 0;
}

Zoomed out of item. 
