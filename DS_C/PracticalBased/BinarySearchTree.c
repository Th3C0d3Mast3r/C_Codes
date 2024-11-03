// Trees use lots of Recursion, thus the functions should have some return type and not void

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;

typedef struct tree{
    Node* root;
    int size;                       // the total nodes that will be exisitng in the tree
}Tree;

void init(Tree* tree){
    tree->root=NULL;
    tree->size=0;
}

Node* createNode(int x){
    Node* newNode=(Node*)(malloc(sizeof(Node)));
    newNode->data=x;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

Node* insertNode(Node* node, int x){
    if(node==NULL){
        return createNode(x);
    }
    if(x < node->data){
        node->left=insertNode(node->left, x);
    }
    else{
        node->right=insertNode(node->right, x);
    }
    return node;
}

void addNode(Tree* tree, int data){
    tree->root=insertNode(tree->root, data);
    tree->size++;   
}

void inOrder(Node* root){
    // PRINTS:- L-D-R
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void preOrder(Node* root){
    // PRINTS:- D-L-R
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node* root){
    // PRINTS:- L-R-D
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int main(){
    Tree tree;
    init(&tree);
    int num;
    while(true){
        printf("VALUE (-1 for Termination): ");
        scanf("%d", &num);
        if(num==-1) break;
        addNode(&tree, num);
    }

    printf("\nPRE-ORDER: ");
    preOrder(tree.root);

    printf("\nPOST-ORDER: ");
    postOrder(tree.root);

    printf("\nIN-ORDER: ");
    inOrder(tree.root);
    return 0;
}