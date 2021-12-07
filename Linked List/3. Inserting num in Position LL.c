/*
2. Inserting: Insert
a) 54 to a sorted array.
c) 99 to position 5.
*/
#include<stdio.h>
#include <stdlib.h>
#define MAX 100


struct node{
    int data;
    struct node *next;
};
int n;
struct node *head;
/*
int value(int a, int n);

*/

void index();
void printList();
int main(){


    head =(struct node *)malloc(sizeof(struct node*));

    struct node *temp = head, *newnode;

    printf("Enter Size of Linked List:  ");
    scanf("%d",&n);

    printf("Enter Sorted Linked list elements:\n ");

    for(int i=0;i<n;i++){
        newnode=(struct node *)malloc(sizeof(struct node*));
        scanf("%d",&newnode->data);
        newnode->next = NULL;

        if(head == NULL){
            head = newnode;
            temp=newnode;
        }else{
            temp->next=newnode;
            temp = temp->next;
        }

    }
/*
    temp = head;
    printf("\n List: ");
    while(temp != NULL){
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

*/

    int choice;

    while(1){
        printf("\n\n:::Menu:::\n");
        printf("1. Insert data with value\n");
        printf("2. Insert data with Index\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){

       /*     case 1: value(head);
                    break; */
            case 2: index();
                    break;
            case 3: exit(0);
            default: printf("Enter valid input...");
        }
    }

    return 0;
}


/*
void value(struct node *a){

    int item,position;
    printf("Enter data to be inserted: ");
    scanf("%d",&item);


    for(int i=0;i<n;i++){

        if (item<a[i]){
            position = i;
            break;
        }else{
            position = i+1;
        }
    }

    for(int j=n+1;j>=position;j--){
            a[j] = a[j-1];
    }

    a[position] = item;
    n=n+1;

    printf("\n\nThe final array: ");
    for(int k=0;k<n;k++){
        printf(" %d ", a[k]);
    }
}

*/

void index(){

   int value,indexvalue;

   printf("Enter position: ");
   scanf("%d",&indexvalue);

   printf("Enter data: ");
   scanf("%d", &value);

   struct node *newNode;
   newNode= (struct node*)malloc(sizeof(struct node*));

   newNode->data=value;
   newNode->next=NULL;

   if(indexvalue==1){
    newNode->next=head;
    head =newNode;
    printList();
    return;
   }

    struct node *temp = head;

    for(int i=0;i<indexvalue-2;i++){
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=temp;
    printList();


}


void printList(){
    struct node * temp;
    temp=head;

    while(temp!= NULL){
    printf(" %d ",temp->data);
    temp=temp->next;
    }
}

/*
 struct node *temp, *newNode;
    newNode = (struct node*)malloc(sizeof(struct node*));

    int indexValue,item;

    printf("\nEnter index no. to insert the data: ");
    scanf("%d",&indexValue);
    printf("Enter data to be inserted: ");
    scanf("%d",&item);

    newNode->data=item;
    newNode->next=NULL;

    temp=head;

    for(int i=2;i<indexValue;i++){
        temp=temp->next;
        if(temp== NULL){
            break;
        }
    }

    if(temp != NULL){
        newNode->next = temp->next;
        temp->next=newNode;
    }

    printf("\n\nFinal Linked list elements: ");

    temp=head;
    while(temp !=NULL){
        printf(" %d ",temp->data);
        temp =temp->next;
    }
    printf("\n");

*/
