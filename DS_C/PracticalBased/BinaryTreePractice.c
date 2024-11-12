#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;

typedef struct tree{
    Node* head;
    int size;
}Tree;

void init(Tree* tree){
    tree->head=NULL;
    tree->size=0;
}

Node* create(Tree* tree){
    int x=0;
    printf(" Value: ");
    scanf("%d", &x);

    if(x==-1) return NULL;
    tree->size++;
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=x;

    printf("Enter the Left Child of %d\n", newNode->data);
    newNode->left=create(tree);

    printf("Enter the Right Child of %d\n", newNode->data);
    newNode->right=create(tree);
    return newNode;
}

void inOrder(Node* head){
    if(head==NULL) return;

    inOrder(head->left);
    printf("%d ", head->data);
    inOrder(head->right);
}


void main(){
    printf("This is a code for BINARY TREE\n");
    Tree tree;
    init(&tree);

    tree.head=create(&tree);

    printf("\n\nTHE INORDER TRAVERSAL IS:- \n");
    inOrder(tree.head);
}