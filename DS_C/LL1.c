/*
This is the first file for linked List in C
We will be using stucts for this-using self referential struct
*/

#include <stdio.h>
#include <stdbool>

typedef struct node{
    int data;
    struct node *link;                               // only one link becuase we have singly linked list
}Node;

Node *head=NULL;                                    // the head is a GLOBAL VARIABLE
Node *current=NULL;                                 // what we will be using to add more nodes to the link

int main()
{
    head=(struct node *)malloc(sizeof(Node));       // the very first node of the linkedlist
    head->data=10;
    head->link=NULL;

    current=(struct node *)malloc(sizeof(Node));
    current->data=98;
    current->link=NULL; 
    head->link=current;                             // current contains the address of the second node
}

// THIS IS JUST FOR TWO NODES LINKED LIST
// BUT THIS IS NOT HOW IT WILL WORK IN REAL LIFE.
// THUS SEE THE SECOND LINKED LIST FILE TO KNOW MORE.