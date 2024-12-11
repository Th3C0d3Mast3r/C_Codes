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

Node* findMin(Node* node) {
    // Find the minimum value node in the right subtree (in-order successor)
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

Node* deleteNode(Node* root, int key) {
    // Base case: Tree is empty
    if (root == NULL) {
        return root;
    }

    // Recur down the tree to find the node to delete
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to be deleted is found

        // Case 1: Node has no child (leaf node)
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: Node has only one child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Node has two children
        // Find the in-order successor (smallest in the right subtree)
        Node* temp = findMin(root->right);
        // Replace the data of the current node with the successor's data
        root->data = temp->data;
        // Delete the in-order successor
        root->right = deleteNode(root->right, temp->data);
    }
    
    return root;
}

void removeNode(Tree* tree, int key) {
    if (tree->root != NULL) {
        tree->root = deleteNode(tree->root, key);
        tree->size--;
    }
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