// THIS IS A CODE FOR USER-INPUT BASED BINARY TREE(using recursion)

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
    int size;
}Tree;

void init(Tree *tree)
{
    tree->root = NULL;
    tree->size = 0;
}

Node* create(Tree *tree)
{
    int x = 0;
    printf("VALUE: ");
    scanf("%d", &x);

    if(x == -1) return NULL;  
    tree->size++;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;

    printf("ENTER LEFT CHILD OF %d\n", x);
    newNode->left = create(tree);

    printf("ENTER RIGHT CHILD OF %d\n", x);
    newNode->right = create(tree);

    return newNode;
}

void inOrder(Node *newNode)
{  
    if (newNode == NULL) return;

    inOrder(newNode->left);                 // L
    printf("%d  ", newNode->data);          // D
    inOrder(newNode->right);                // R
}

void postOrder(Node *roots)
{
    if (roots == NULL) return;
    
    postOrder(roots->left);                 // L
    postOrder(roots->right);                // R
    printf("%d ", roots->data);             // D
}


int main()
{
    Tree tree;
    init(&tree);

    tree.root = create(&tree);
    printf("\n\nTHUS, the TREE in INORDER TRAVERSAL IS: ");
    inOrder(tree.root);
    printf("\n\nTHUS, the TREE in POSTORDER TRAVERSAL IS: ");
    postOrder(tree.root);

    return 0;
}
