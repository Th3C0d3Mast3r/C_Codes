// the following is a code written by my fellow classmate- Varad Chipkar

#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* left;
    struct node* right;
    int height;
};
struct node* getnode(int d){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = d;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}
int maxDepth(struct node* root){
    if (root == NULL)
    return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}
int BF(struct node* root)
{
return (root ? maxDepth(root->left) - maxDepth(root->right) : 0);
}
struct node* rotateRight(struct node* root)
{
struct node* newRoot = root->left;
printf("\na: %d, b : %d, c : %d",root->data, newRoot->data, ((newRoot->right!=NULL)?
newRoot->right->data:0));
root->left = newRoot->right;
newRoot->right = root;
root->height = 1 + maxDepth(root->left) > maxDepth(root->right) ? maxDepth(root->left) :
maxDepth(root->right);
newRoot->height = 1 + (newRoot->left ? newRoot->left->height : 0) > (newRoot->right ?
newRoot->right->height : 0) ? (newRoot->left ? newRoot->left->height : 0) : (newRoot->right ?
newRoot->right->height : 0);
return newRoot;
}
struct node* rotateLeft(struct node* root)
{
struct node* newRoot = root->right;

printf("\na: %d, b : %d, c : %d",root->data, newRoot->data,((newRoot->left!=NULL)?newRoot->left->data:0));
root->right = newRoot->left;
newRoot->left = root;
root->height = 1 + maxDepth(root->left) > maxDepth(root->right) ? maxDepth(root->left) :
maxDepth(root->right);
newRoot->height = 1 + (newRoot->left ? newRoot->left->height : 0) > (newRoot->right ?
newRoot->right->height : 0) ? (newRoot->left ? newRoot->left->height : 0) : (newRoot->right ?
newRoot->right->height : 0);
return newRoot;
}
struct node* balance(struct node* root)
{
if (BF(root) > 1) {
if (BF(root->left) < 0) // Left Right Case
{printf("\nLR case : ");
root->left = rotateLeft(root->left);
}printf("\nLL case : ");
return rotateRight(root); // Left Left Case
}
if (BF(root) < -1) {
if (BF(root->right) > 0) {// Right Left Case
printf("\nRL case : ");
root->right = rotateRight(root->right);}
printf("\nRR case : ");
return rotateLeft(root); // Right Right Case
}
return root;
}
struct node* insert(struct node* root, int d)
{
if (root == NULL)
return getnode(d);
if (d < root->data)
root->left = insert(root->left, d);
else if (d > root->data)
root->right = insert(root->right, d);
root->height = 1 + maxDepth(root->left) > maxDepth(root->right) ? maxDepth(root->left) :
maxDepth(root->right);
return (root);
}
struct node* findMin(struct node* root)
{
while (root->left != NULL) {
root = root->left;
}
return root;

}
struct node* deleteNode(struct node* root, int key)
{
if (root == NULL)
return root;

if (key < root->data)
root->left = deleteNode(root->left, key);
else if (key > root->data)
root->right = deleteNode(root->right, key);
else {
if ((root->left == NULL) || (root->right == NULL)) {
struct node* temp = root->left ? root->left : root->right;
if (temp == NULL) {
temp = root;
root = NULL;
} else
*root = *temp;
free(temp);
} else {
struct node* temp = findMin(root->right);
root->data = temp->data;
root->right = deleteNode(root->right, temp->data);
}
}
if (root == NULL)
return root;
root->height = 1 + (maxDepth(root->left) > maxDepth(root->right) ? maxDepth(root->left) :
maxDepth(root->right));
return balance(root);
}
void print(struct node* n)
{
if (n == NULL)
return;
printf("\t%d", n->data);
print(n->left);
print(n->right);
}
struct node* search(struct node* root, int n)

{
if (root == NULL)
return NULL;
if (root->data == n)
return root;
if (root->data < n)
return search(root->right, n);
return search(root->left, n);
}

int main()
{
struct node* root = NULL;
root = insert(root, 10);
root = insert(root, 5);
root = insert(root, 13);
root = insert(root, 36);
root = insert(root, 27);
root = insert(root, 23);
root = insert(root, 2);
root = insert(root, 1);
printf("Preorder traversal before deletion: \n");
print(root);
printf("\n");
printf("Balancing factor of 13 = %d\n", BF(search(root, 13)));
printf("Balancing factor of 36 = %d\n", BF(search(root, 36)));
printf("Balancing factor of 23 = %d\n", BF(search(root, 23)));

root = deleteNode(root, 10);
printf("\n\nPreorder traversal after deleting 10: \n");
root=balance(root);
print(root);
printf("\n");
printf("Balancing factor of 13 = %d\n", BF(search(root, 13)));
printf("Balancing factor of 36 = %d\n", BF(search(root, 36)));
printf("Balancing factor of 23 = %d\n", BF(search(root, 23)));
return 0;
}