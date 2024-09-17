#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node
{
    char data;
    struct node* left;
    struct node* right;
} Node;

typedef struct tree
{
    Node *root;
    int size;
} Tree;

typedef struct stack
{
    Node *array[100];
    int top;
} Stack;

void init(Tree *tree)
{
    tree->root = NULL;
    tree->size = 0;
}

Node* createNode(Tree *tree, char x)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    tree->size++;
    return newNode;
}

void push(Stack *stack, Node* node)
{
    stack->array[++stack->top] = node;
}

Node* pop(Stack *stack)
{
    return stack->array[stack->top--];
}

Node* peek(Stack *stack)
{
    return stack->array[stack->top];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);               // L
        printf("%c ", root->data);         // D
        inOrder(root->right);              // R
    }
}

Node* buildExpressionTree(Tree *tree, char postfix[])   // array, because stack is taken as array
{
    Stack stack;
    stack.top = -1;
    
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];
        
        if (isalnum(ch))
        {  
            // If operand, create a node and push to stack
            Node *operandNode = createNode(tree, ch);
            push(&stack, operandNode);
        } 
        else if (isOperator(ch))
        {  
            // If operator, pop two operands
            Node *operatorNode = createNode(tree, ch);
            operatorNode->right = pop(&stack);
            operatorNode->left = pop(&stack);
            push(&stack, operatorNode);
        }
    }
    
    return pop(&stack);  // The final node in stack will be the root of the tree
}

int main() {  
    Tree tree;  
    init(&tree);
    char str[200];
    printf("Enter the POSTFIX EXPRESSION BELOW:-");
    scanf(" %s", &str);
    printf("\n");

    // we use the given postfix and form our tree
    tree.root = buildExpressionTree(&tree, str);    // passing our tree and the stack

    // Perform in-order traversal (which will give infix expression)
    printf("Infix expression: ");
    inOrder(tree.root);
    printf("\n");

    return 0;
}
