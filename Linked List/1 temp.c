#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
struct node *getNewNode(int val);
struct node *insert(struct node *root, int val);
void inorder(struct node *root);
int main(){

    root = insert(root,20);
    root = insert(root,32);
    root = insert(root,27);
    root = insert(root,11);
    root = insert(root,41);

    inorder(root);

    return 0;
}

struct node *getNewNode(int val){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->key   = val;
    newNode->left  = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node *insert(struct node *root, int val){

    if(root == NULL)
        return getNewNode(val);

    if(root->key < val) // left
        root->right = insert(root->right,val);

    else if(root->key > val) //right
        root->left = insert(root->left,val);

    return root;
}

void inorder(struct node *root){
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
}

/* while(1){
        printf("1. Insert node:");
        printf("2. Exit");

        int choice;
        printf("Enter Choice:  ");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter value: ");
                    scanf("%d",&value);
                    insert(root,value);
            break;
            case 2: exit(0);
            default: printf("Enter valid input!\n");

        }
    }*/

