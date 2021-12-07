
/*
 * Program  : Binary Search Tree insertion
 * Language : C
 */
#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node *left;
    struct node *right;
};

//this function will return the new node with the given value
struct node *getNewNode(int val){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->key   = val;
    newNode->left  = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node *insert(struct node *root, int val){
    /*
     * It will handle two cases,
     * 1. if the tree is empty, return new node in root
     * 2. if the tree traversal reaches NULL, it will return the new node
     */
    if(root == NULL)
        return getNewNode(val);
    /*
     * if given val is greater than root->key,
     * we should find the correct place in right subtree and insert the new node
     */
    if(root->key < val)
        root->right = insert(root->right,val);
    /*
     * if given val is smallar than root->key,
     * we should find the correct place in left subtree and insert the new node
     */
    else if(root->key > val)
        root->left = insert(root->left,val);
    /*
     * It will handle two cases
     * (Prevent the duplicate nodes in the tree)
     * 1.if root->key == val it will straight away return the address of the root node
     * 2.After the insertion, it will return the original unchanged root's address
     */
    return root;
}

/*
 * it will print the tree in ascending order
 * we will discuss about it in the upcoming tutorials
 */
void inorder(struct node *root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
}

int main()
{
    struct node *root = NULL;
    root = insert(root,100);
    root = insert(root,50);
    root = insert(root,150);
    root = insert(root,50);

    inorder(root);

    return 0;
}

struct node *deleteNode(struct node *root, int key) {
      // Return if the tree is empty
      if (root == NULL) return root;

      // Find the node to be deleted
      if (key < root->key)
        root->left = deleteNode(root->left, key);
      else if (key > root->key)
        root->right = deleteNode(root->right, key);

      else {
            // If the node is with only one child or no child
            if (root->left == NULL) {
                struct node *temp = root->right;
                free(root);
                return temp;
            } else if (root->right == NULL) {
                struct node *temp = root->left;
                free(root);
                return temp;
            }

        // If the node has two children
        struct node *temp = minValueNode(root->right);

        // Place the inorder successor in position of the node to be deleted
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
      }
  return root;
}
