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

Node* rightRotate(Node *node) {
    Node *x = node->left;
    Node *temp = x->right;

    // Perform rotation
    x->right = node;
    node->left = temp;  // Should update the left of the original node

    return x;  // the new root
}

Node* leftRotate(Node *node) {
    Node *x = node->right;
    Node *temp = x->left;

    // Perform rotation
    x->left = node;
    node->right = temp;  // Should update the right of the original node

    return x;  // the new root
}

int balance(Node *node){
    if(node==NULL){
        return 0;
    }
    return height(node->left)-height(node->right);
}

// Now, adding the NODE would be one off the toughest part
Node* addNode(Node *node, int x) {
    if (node == NULL) {
        return makeNode(x);  // Creating new node
    }

    if (x < node->data) {
        node->left = addNode(node->left, x);
    } else if (x > node->data) {
        node->right = addNode(node->right, x);
    } else {
        return node;  // No duplicates allowed
    }

    int bal = balance(node);

    // Left Left Case
    if (bal > 1 && x < node->left->data) {
        return rightRotate(node);
    }

    // Right Right Case
    if (bal < -1 && x > node->right->data) {
        return leftRotate(node);
    }

    // Left Right Case
    if (bal > 1 && x > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (bal < -1 && x < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void insert(Tree *tree, int x){
    tree->root=addNode(tree->root, x);
    (tree->size)++;
}

void inOrder(Node *node){
    if(node!=NULL){
        inOrder(node->left);
        printf("%d ", node->data);
        inOrder(node->right);
    }
}


int main()
{
    Tree tree;
    init(&tree);

    int val;
    while(1==1){
        printf("Enter Value (-1 to stop entering):- ");
        scanf("%d", &val);
        if(val==-1){
            break;
        }
        insert(&tree, val);
        inOrder(tree.root);
        printf("\n");
    }

    printf("\nFINAL AVL TREE INORDER\n");
    inOrder(tree.root);
}