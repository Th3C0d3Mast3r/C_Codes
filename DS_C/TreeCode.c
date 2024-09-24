// the following is a code to show BINARY SEARCH TREE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;

typedef struct tree{
    Node *root;
    int size;
}Tree;

void init(Tree *tree){
    tree->node=NULL;
    tree->size=0;
}

Node* createNode(int x)
{
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=x;
    newNode->right=NULL;
    newNode->left=NULL;
    return newNode;
}

Node* insertNode(Node *root, int x){
    if(root==NULL){
        return createNode(x);
    }
    if(x < root->data){
        root->left=insertNode(node->left, x);
    }
    else{
        root->right=insertNode(node->right, x);
    }

    return root;
}

void addNode(Tree *tree, int x){
    tree->root=insertNode(tree->root, x);
    tree->size++;
}

bool isPresent(Node *root, int x){
    if(root->data==x || root==NULL){
        return root->data;
    }
    if(x < root->data){
        isPresent(root->left);
    }
    else{
        isPresent(root->right);
    }
}

Node* deleteNode(Node *root, int x)                 // NOTE THAT THIS FUNCTION IS ONLY CALLED WHEN isPresent() returns true; 
{
    if(root==NULL){
        return root;
    }
    else if(x < root->data){
        root->left=deleteNode(root->left);
    }
    else if(x > root->data){
        root->right=deleteNode(root->right);
    }

    Node *temp=(Node*)malloc(sizeof(Node));

    else{
        // CASE WHERE THAT HAS ONLY ONE CHILD
        if(root->left==NULL){
            temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            temp=root->left;
            free(root);
            return temp;
        }

        // WHEN THE NODE HAS TWO CHILDREN
        temp=findMin(root->right, x);
        root->data=temp->data;
        root->right=deleteNode(root->right, temp->data);
        return root;
    }

}