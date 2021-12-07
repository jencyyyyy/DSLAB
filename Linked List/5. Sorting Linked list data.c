#include<stdio.h>
#include<stdlib.h>

int n;
void createlist(int n);
void printlist();
void sortlist();
struct node{
    int data;
    struct node *next;

};

struct node *head =NULL;



int main(){

    int n;

    printf("\nEnter Size of Linked List: ");
    scanf("%d",&n);

    createlist(n);

    printf("\nGiven List\n");
    printlist();

    sortlist();

    printf("\nSorted list\n");
    printlist();

    printf("\n");


    return 0;
}

void createlist(int n){
    struct node *temp;
    printf("Enter data:\n");
    int value;

    for(int i=0;i<n;i++){
        struct node *newNode= (struct node*)malloc(sizeof(struct node*));
        scanf("%d",&newNode->data);
        newNode->next=NULL;

        if(head==NULL){
            head=newNode;
            temp= newNode;
        }else{
            temp->next= newNode;
            temp= newNode;
        }
    }
}

void printlist(){
    struct node *temp;
    temp=head;

    if(temp==NULL){
        printf("\nEmpty list\n");
    }

    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void sortlist(){
    struct node *current=head,*index=NULL;
    int temp;
    if(head==NULL){
        printf("\nList is empty.\n");
        exit(0);
    }

    while(current!=NULL){
        index = current->next;
        while(index!=NULL){
            if(current->data>index->data){
                temp = current->data;
                current->data=index->data;
                index->data=temp;
            }
            index= index->next;
        }
        current=current->next;
    }
}
