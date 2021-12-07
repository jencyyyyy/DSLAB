/*1. Create a Linked List and store the value 5, 3, 9, 42, 0, 10.*/

#include<stdio.h>

struct node{
    int data;
    struct node *next;
};

struct node *root=NULL,*temptr;

int main(){
    int n;
    printf("Enter Size of list: ");
    scanf("%d",&n);
    printf("Enter data: ");

    for(int i=0;i<n;i++){
        struct node *newptr = (struct node*)(malloc(sizeof(struct node)));
        scanf("%d",&newptr->data);
        newptr->next=NULL;

        if(root==NULL){
            root = newptr;
            temptr=newptr;
        }else{
            temptr->next=newptr;
            temptr=newptr;
        }
    }
    printf("\nEntered list:\n");
    temptr=root;

    for(int i=0;i<n;i++){
        printf(" %d ",temptr->data);
        temptr=temptr->next;
    }
    return 0;
}
