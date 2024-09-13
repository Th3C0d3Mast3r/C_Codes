/**
 * 				     1
 * 				   2     3        
 *				 4   5  6  7  
 * */



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

Node* createNode(Tree *tree, int x)
{
    Node *newNode = (Node*)malloc(sizeof(Node));

    // if (newNode == NULL) {
    //     perror("Failed to allocate memory for new node");
    //     exit(EXIT_FAILURE);
    // }

    newNode->data = x;
    newNode->right = NULL;
    newNode->left = NULL;
    tree->size++;
    return newNode;
}

void inOrder(Node *root) {  			// Logic for in-order traversal
    if (root != NULL) {
        inOrder(root->left);			// L
        printf("%d ", root->data);		// D
        inOrder(root->right);			// R
    }
}

int leafCount=0;						// global variable for getting the count of leaves in the tree

int leafNo(Node *root)
{  			
	

    if (root != NULL)
    {
        leafNo(root->left);
        if(root->left==NULL && root->right==NULL)	leafCount++;
        leafNo(root->right);			
    }
    return leafCount;
}

int depth = -1;
int depthFinder(Node *root, int x, int currentDepth)
{
    if (root == NULL) return -1;
    if (root->data == x) return currentDepth;
    
    int leftDepth = depthFinder(root->left, x, currentDepth + 1);
    if (leftDepth != -1) return leftDepth;
    
    return depthFinder(root->right, x, currentDepth + 1);
}

int main() {  
    Tree tree;  
    init(&tree);

    Node *n1 = createNode(&tree, 1);
    Node *n2 = createNode(&tree, 2);
    Node *n3 = createNode(&tree, 3);
    Node *n4 = createNode(&tree, 4);
    Node *n5 = createNode(&tree, 5);
    Node *n6 = createNode(&tree, 6);
    Node *n7 = createNode(&tree, 7);

    // Logic for making the tree
    tree.root = n1;
    n1->left = n2;
    n1->right = n3;

    n2->left = n4;
    n2->right = n5;

    n3->left = n6;
    n3->right = n7;

    // Perform in-order traversal
    inOrder(tree.root);
    printf("\n\nAND THE TOTAL NODES PRESENT ARE:- %d\n", tree.size);	

    int totalLeaf=leafNo(tree.root);
    printf("TOTAL LEAF PRESENT:- %d\n", totalLeaf);

    int target = 5;
    int h = depthFinder(tree.root, target, 0);
    if (h != -1) {
        printf("Depth of node with data %d: %d\n", target, h);
    }
    else {
        printf("Node with data %d not found in the tree.\n", target);			// IF THAT DOESNT EXIST
    }

    return 0;
}
