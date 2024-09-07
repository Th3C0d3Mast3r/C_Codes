// this is a base code for Binary Search Tree- putting the inputs sorted with smaller in left subtree, and larger in right
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
    tree->root = NULL;
    tree->size = 0;
}

Node* createNode(int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node *node, int x) {
    if (node == NULL) {
        return createNode(x);
    }

    if (x < node->data) {
        node->left = insertNode(node->left, x);         // Recursive insert on left
    } else {
        node->right = insertNode(node->right, x);       // Recursive insert on right
    }

    return node;
}

// Adds the Made node to the given tree
void addNode(Tree *tree, int x) {
    tree->root = insertNode(tree->root, x);
    tree->size++;
}

void inOrder(Node *root) {                              // logic for inoder traversal
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main() {
    Tree trees;
    char ch;
    bool loops = true;

    init(&trees);

    while (loops) {
        printf("\n1) ADD NODE\n2) IN-ORDER TRAVERSAL\n3) EXIT\n");
        printf("What Would You Like to do in TREE: ");
        scanf(" %c", &ch);
        
        if (ch == '1') {
            int d;
            printf("Enter the Data: ");
            scanf("%d", &d);
            addNode(&trees, d);
        } else if (ch == '2') {
            printf("In-order Traversal: ");
            inOrder(trees.root);
            printf("\n");
        } else if (ch == '3') {
            printf("Exiting the code!\n");
            loops = false;
        } else {
            printf("WRONG INPUT! Try Again.\n");
        }
    }

    return 0;
}
