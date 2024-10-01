// this is the first code for AVL Tree
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;

typedef struct tree{
    Node* root;
    int size;
}Tree;

void init(Tree *tree){
    tree->root=NULL;
    tree->size=0;
}

Node* makeNode(int x){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=x;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

int height(Node *node){
    if(node==NULL){
        return 0;
    }
    int leftHeight=height(node->left);
    int rightHeight=height(node->right);

    return 1 + (leftHeight>rightHeight ? leftHeight : rightHeight);;
}

Node* rightRotate(Node *node){
    Node *x=node->left;
    Node *temp=x->right;

    // Now we begin the rotation
    x->right=node;
    x->left=temp;

    return x;       // the new Sub-Root
}

// both the functions are same-just make right left, and vice versa
Node* leftRotate(Node *node){
    Node *x=node->right;
    Node *temp=x->left;

    // Now we begin the rotation
    x->left=node;
    x->right=temp;

    return x;       // the new Sub-Root
}

