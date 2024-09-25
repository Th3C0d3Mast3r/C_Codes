#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

typedef struct tree {
    Node *root;
    int size;
} Tree;

void init(Tree *tree) {
    tree->root = NULL;  // Fixed typo: tree->root, not tree->node
    tree->size = 0;
}

Node* createNode(int x) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

Node* insertNode(Node *root, int x) {
    if (root == NULL) {
        return createNode(x);
    }
    if (x < root->data) {
        root->left = insertNode(root->left, x);  // Fixed root->left, not node->left
    } else {
        root->right = insertNode(root->right, x);  // Fixed root->right, not node->right
    }
    return root;
}

void addNode(Tree *tree, int x) {
    tree->root = insertNode(tree->root, x);
    tree->size++;
}

bool isPresent(Node *root, int x) {
    if (root == NULL) {
        return false;  // Fixed: added check for root == NULL
    }
    if (root->data == x) {
        return true;
    }
    if (x < root->data) {
        return isPresent(root->left, x);
    } else {
        return isPresent(root->right, x);
    }
}

Node* findMin(Node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node *root, int x) {
    if (root == NULL) {
        return root;
    }
    if (x < root->data) {
        root->left = deleteNode(root->left, x); // recursion
    } else if (x > root->data) {
        root->right = deleteNode(root->right, x);  
    } else {
        // Node found
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        //  get the inorder successor (smallest in the right subtree)
        Node *temp = findMin(root->right); 
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    Tree myTree;
    init(&myTree);

    addNode(&myTree, 50);
    addNode(&myTree, 30);
    addNode(&myTree, 70);
    addNode(&myTree, 20);
    addNode(&myTree, 40);
    addNode(&myTree, 60);
    addNode(&myTree, 80);

    // Testing the functions
    printf("Is 40 present? %s\n", isPresent(myTree.root, 40) ? "Yes" : "No");
    printf("Is 25 present? %s\n", isPresent(myTree.root, 25) ? "Yes" : "No");

    myTree.root = deleteNode(myTree.root, 40);
    printf("After deletion, is 40 present? %s\n", isPresent(myTree.root, 40) ? "Yes" : "No");

    return 0;
}
