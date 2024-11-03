#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node* next;
} Node;

typedef struct list{
    Node* head;
    int size;
} List;

void init(List* list){
    list->head = NULL;
    list->size = 0;
}

void add(List* list, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));    // Fix: Allocate memory for Node, not Node*
    newNode->data = data;
    newNode->next = NULL;
    list->size++;
    if(list->head == NULL){
        list->head = newNode;
        return;
    }
    Node* temp = list->head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

List* performAddition(List* list1, List* list2){
    List* newList = (List*)malloc(sizeof(List));    // Fix: Allocate memory for newList
    init(newList);

    Node* temp1 = list1->head;
    Node* temp2 = list2->head;

    while(temp1 != NULL && temp2 != NULL){
        add(newList, temp1->data + temp2->data);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return newList;
}

void display(List* list){
    Node* temp = list->head;
    int xs=list->size-1;
    while(temp != NULL){
        if(xs==0){
            printf("%d", temp->data);
            break;
        }
        printf("(%dx^%d) + ", temp->data, xs);
        xs--;
        temp = temp->next;
    }
    // printf("NULL\n");
}

int main(){
    List list1;
    List list2;
    init(&list1);
    init(&list2);
    int maxPower = 0;

    printf("Highest Power of x in Polynomial: ");
    scanf("%d", &maxPower);

    int x1, x2;

    while(maxPower >= 0){
        if(maxPower == 0){
            printf("CONSTANT for Polynomial-1: ");
            scanf("%d", &x1);
            printf("CONSTANT for Polynomial-2: ");
            scanf("%d", &x2);                       // Fix: Correct variable name for Polynomial-2
            add(&list1, x1);
            add(&list2, x2);
            break;
        }
        printf("Coefficient of x^%d for Polynomial-1 (Enter 0 if that Power Doesn't Exist): ", maxPower);
        scanf("%d", &x1);
        printf("Coefficient of x^%d for Polynomial-2 (Enter 0 if that Power Doesn't Exist): ", maxPower);
        scanf("%d", &x2);
        add(&list1, x1);
        add(&list2, x2);
        printf("\n");
        maxPower--;
    }
    
    printf("\n\nTHE ADDITION OF THE TWO POLYNOMIALS IS:\n");
    display(performAddition(&list1, &list2));

    return 0;
}
