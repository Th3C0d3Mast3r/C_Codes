// this is the code for LinkedList Ploynomial addition code.
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int coeff;
    int pow;
    struct node* link;
} Node;

typedef struct list
{
    Node *head;
    int size;
} List;

void init(List *list)
{
    list->head = NULL;
    list->size = 0;
}

void insert(List *list, int x, int y)               // x serves as coeff while y as power
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->coeff = x;
    newNode->pow = y;
    newNode->link = list->head;
    list->head = newNode;
    list->size++;
}

void printList(List *list)  
{
    Node *current = list->head;
    while (current != NULL)
    {
        printf(" %dx^%d", current->coeff, current->pow);
        current = current->link; // Move to the next node
        if (current != NULL)
            printf(" ->");
    }
}

void addingLists(List *list1, List *list2, List *result)
{
    Node *current1 = list1->head;
    Node *current2 = list2->head;

    while (current1 != NULL && current2 != NULL)
    {
        if (current1->pow > current2->pow)
        {
            insert(result, current1->coeff, current1->pow);
            current1 = current1->link;
        }
        else if (current1->pow < current2->pow)
        {
            insert(result, current2->coeff, current2->pow);
            current2 = current2->link;
        }
        else
        {
            insert(result, current1->coeff + current2->coeff, current1->pow);
            current1 = current1->link;
            current2 = current2->link;
        }
    }

    // If list1 is not empty, add remaining nodes
    while (current1 != NULL)
    {
        insert(result, current1->coeff, current1->pow);
        current1 = current1->link;
    }

    // If list2 is not empty, add remaining nodes
    while (current2 != NULL)
    {
        insert(result, current2->coeff, current2->pow);
        current2 = current2->link;
    }
}

int main()
{
    List list1;
    List list2;
    List result;

    init(&list1);
    init(&list2);
    init(&result);              // Initialize the result list

    //we initialize the lists with the data that we want-not user data

    insert(&list1, 12, 0);      // Insertion in list1
    insert(&list1, 10, 1);
    insert(&list1, -12, 3);
    insert(&list1, 3, 4);

    insert(&list2, 50, 0);      // Insertion in list2
    insert(&list2, 15, 1);
    insert(&list2, 4, 3);

    printf("List 1:");
    printList(&list1);
    printf("List 2:");
    printList(&list2);

    addingLists(&list1, &list2, &result);
    printf("Result:");
    printList(&result);

    return 0;
}
