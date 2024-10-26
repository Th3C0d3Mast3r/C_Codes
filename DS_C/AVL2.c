// LEARNING ABOUT THE IMPORTANCE OF HEIGHT, WE INCLUDE HEIGHT AS A DATA IN THE STRUCT

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct node {
    int data;
    struct node* right;
    struct node* left;
    int height;  // Store the height of the node
} Node;

typedef struct tree {
    Node *root;
    int totNodes;
} Tree;

void init(Tree *tree) {
    tree->root = NULL;
    tree->totNodes = 0;
}

Node* makeNode(int x) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;  // Height is 1 for a new node (leaf)
    return newNode;
}

int getHeight(Node* node) {
    if (node == NULL) return 0;  // Height of NULL node is 0
    return node->height;
}

int getBalance(Node* node) {
    if (node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);  // Balance factor: left - right heights
}


// Right rotation 
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Rotation jaha hoga
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));

    return x;
}

// Left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Rotation happens
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));

    return y; 
}


Node* insertNode(Tree *tree, Node *node, int x) {
    if (node == NULL) {
        return makeNode(x);
    }

    if (x < node->data) {
        node->left = insertNode(tree, node->left, x);
    }
    else if (x > node->data) {
        node->right = insertNode(tree, node->right, x);
    }
    else {
        return node;  // Duplicate keys are not allowed
    }

    // Update height of the current node
    node->height = 1 + (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right));

    // Calculate balance factor
    int balance = getBalance(node);
    printf("%d has the balance factor %d\n", node->data, balance);  // Print balance factor for the node

    // Balancing the tree with the message of what has happened and everything needed

    // Left Left Case 
    if (balance > 1 && x < node->left->data){
        printf("Addition of New Node created Imbalance of LEFT-LEFT. Thus, Performing a RIGHT ROTATION\n");
        return rightRotate(node);
    }
       

    // Right Right Case 
    if (balance < -1 && x > node->right->data){
         printf("Addition of New Node created Imbalance of RIGHT-RIGHT. Thus, Performing a LEFT ROTATION\n");
        return leftRotate(node);
    }
       

    // Left Right Case
    if (balance > 1 && x > node->left->data) {
        printf("Addition of New Node created Imbalance of LEFT-RIGHT. Thus, Performing a LEFT and then RIGHT ROTATION\n");
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case 
    if (balance < -1 && x < node->right->data) {
        printf("Addition of New Node created Imbalance of RIGHT-LEFT. Thus, Performing a RIGHT & then LEFT ROTATION\n");
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;  // Return the (unchanged) node pointer
}


// deleting the node and the logic behind that:-
Node* deleteNode(Tree *tree, Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data) root->left = deleteNode(tree, root->left, key);

    else if (key > root->data) root->right = deleteNode(tree, root->right, key);

    else                // WHEN WE HAVE LOCATED THE DELETE KARNE KA NODE
    {
        if (root->left == NULL || root->right == NULL)  // LEAF NODE CASE
        {
            Node* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;

            free(temp);
        }
        else {
            Node* temp = root->right;
            while (temp->left != NULL) temp = temp->left;

            root->data = temp->data;
            root->right = deleteNode(tree, root->right, temp->data);
        }
    }

    if (root == NULL) return root;

    root->height = 1 + (getHeight(root->left) > getHeight(root->right) ? getHeight(root->left) : getHeight(root->right));

    int balance = getBalance(root);
    printf("%d has the balance factor %d\n", root->data, balance);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0) {
        printf("Left-Left case at node %d. Performing right rotation.\n", root->data);
        return rightRotate(root);
    }

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        printf("Left-Right case at node %d. Performing left-right rotation.\n", root->data);
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0) {
        printf("Right-Right case at node %d. Performing left rotation.\n", root->data);
        return leftRotate(root);
    }

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        printf("Right-Left case at node %d. Performing right-left rotation.\n", root->data);
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void preOrder(Node* root){
    if(root!=NULL){
        printf("%d", &root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void delete(Tree *tree, int x) {
    tree->root = deleteNode(tree, tree->root, x);
    (tree->totNodes)--;
}

void add(Tree *tree, int x) {
    tree->root = insertNode(tree, tree->root, x);
    (tree->totNodes)++;
}

int main() {
    Tree tree;
    init(&tree);

    while(true){
        int num=0;
        printf("Enter a Value (To Escape, Enter -1):-");
        scanf("%d", &num);
        if(num==-1) break;
        add(&tree, num);
    }
    
    inOrder(tree.root);

    printf("Now, We will Perform the Node Deletion:- ");
    while(true){
        int num=0;
        printf("Enter the Node You Wish to Delete:- ");
        scanf("%d", &num);
        if(num==-1) break;
        delete(&tree, num);
        printf("\n The Pre-Order of the Tree is coming to:- ");
        preOrder(tree.root);
    }


}
