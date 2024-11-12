// there might be some error in this code. Do check and then use!
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node {
    char data;
    struct node* left;
    struct node* right;
} Node;

Node* newNode(char data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}


bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

Node* postfixToExpressionTree(char* postfix) {
    Node* stack[100]; // Stack to hold nodes
    int top = -1;     // Stack pointer

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        
        if (!isOperator(ch)) {
            Node* operandNode = newNode(ch);
            stack[++top] = operandNode;
        }
        
        else if (isOperator(ch)) {
            Node* operatorNode = newNode(ch);
            operatorNode->right = stack[top--];  // Right child
            operatorNode->left = stack[top--];   // Left child

            stack[++top] = operatorNode;
        }
    }

    return stack[top];
}

void inorderTraversal(Node* root) {
    if (root != NULL){
        inorderTraversal(root->left);
        printf("%c ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    char postfix[100];
    printf("Enter the POSTFIX EXPRESSION: ");
    scanf("%s", &postfix);

    Node* root = postfixToExpressionTree(postfix);

    printf("Inorder Traversal of the Expression Tree:\n");
    inorderTraversal(root);

    return 0;
}
