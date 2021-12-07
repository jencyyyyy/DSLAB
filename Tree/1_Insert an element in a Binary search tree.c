#include<stdio.h>
#include<stdlib.h>

typedef struct BST{
    int data;
    struct BST *left;
    struct BST *right;
}node;

node *create();
void insert(node *,node *);
void inorder(node *);

int main(){
    char ch;
    node *root=NULL,*temp;
    int choice;

    do{
        temp=create();

        if(root==NULL)
            root=temp;
        else
            insert(root,temp);

        printf("\nDo you want to enter more(y/n)?");
        getchar();
        scanf("%c",&ch);
    }while(ch=='y'|ch=='Y');

    printf("\nInorder Traversal: ");
    inorder(root);
    return 0;
}

node *create(){
    node *temp;
    printf("\nEnter data: ");

    temp=(node*)malloc(sizeof(node));

    scanf("%d",&temp->data);
    temp->left=temp->right=NULL;

    return temp;
}

void insert(node *root,node *temp){
    if(temp->data<root->data){
        if(root->left!=NULL)
            insert(root->left,temp);
        else
            root->left=temp;
    }
    if(temp->data>root->data){
        if(root->right!=NULL)
            insert(root->right,temp);
        else
            root->right=temp;
    }
}

void inorder(node *root){
    if(root!=NULL){

        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

/*
    while(1){
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Diaplay\n");
        printf("3. Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&choice);

        wc
    }

*/
