#include<stdio.h>
#include<stdlib.h>

struct node {

    int data;
    struct node *next;
};

struct node *head;
int n;

int main(){
    int item;
    printf("Enter size of Linked list: ");
    scanf("%d",&n);

    printf("Enter Linked list elements: ");

    struct node *head = (struct node*)malloc(sizeof(struct node*));

    struct node *temp = head;
    for(int i=0;i<n;i++){

        scanf("%d",&item);

        if(head == NULL){
            head->data = item;
            head->next=NULL;
        }else{

            struct node *newNode = (struct node*)malloc(sizeof(struct node*));

            newNode->data = item;
            newNode-> next =NULL;

            while(temp!=NULL){
                temp = temp->next;
            }
            temp = newNode;
        }
    }
    printf("\n\nRequired list: ");

    temp=head;

    while(temp!=NULL){
        printf(" %d ", temp->data);
        temp=temp->next;
    }
}
