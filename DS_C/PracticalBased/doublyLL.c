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

void add(List *list, int x)
{
    Node *n = malloc(sizeof(Node));                                 // Node to be added
    n->data = x;
    n->next = NULL;
    list->size++;

    if (list->head == NULL)
    { 
        n->prev = NULL;                                             // If the list is empty, the new node is the head
        list->head = n;
        return;
    }

    Node *temp = list->head;
    while (temp->next != NULL) 
    {
        temp = temp->next;                                          // Traverse to the last node
    }
    temp->next = n;
    n->prev = temp;
}

void addPrev(List *list, int x)
{
    Node *n = malloc(sizeof(Node));
    n->data = x;
    n->prev = NULL;
    n->next = list->head;
    list->size++;

    if (list->head != NULL)
    { 
        list->head->prev = n;                                       // If the list is not empty, update the previous head
    }

    list->head = n;
}

void addAtPos(List* list, int data, int loc){
    if(loc == 0){  
        addPrev(list, data);
        return;
    }
    if(loc == list->size){ 
        add(list, data);
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    Node* temp = list->head;
    while(loc > 1 && temp != NULL){
        loc--;
    }

    if (temp == NULL || temp->next == NULL) {   // Fix: Handle case where temp->next is NULL
        add(list, data);                        // Add at the end if `loc` is invalid or temp is at the end
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    list->size++;
}

void display(List* list){
    Node* temp = list->head;

    while(temp != NULL){
        printf("%d <=> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    List list;
    init(&list);
    int x, pos;

    while(true){
        printf("(1) PUSH DATA\n(2) ADD AT START\n(3) ADD AFTER LOCATION\n(4) EXIT\n");
        scanf("%d", &x);

        if(x == 1){
            printf("Value: ");
            scanf("%d", &x);
            add(&list, x);
            printf("\n");
            display(&list);
            printf("\n");
        }
        else if(x == 2){
            printf("Value: ");
            scanf("%d", &x);
            addPrev(&list, x);
            printf("\n");
            display(&list);
            printf("\n");
        }
        else if(x == 3){
            printf("Value: ");
            scanf("%d", &x);
            printf("Position: ");
            scanf("%d", &pos);
            addAtPos(&list, x, pos);
            printf("\n");
            display(&list);
            printf("\n");
        }
        else  break;
    }

    printf("BYE BYE :)\n");
    return 0;
}