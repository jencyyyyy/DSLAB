/*2. Traversing: Perform same operations as done on Array.


1. Traversing: carry out the following operations on an Array
a) Maximum Value b) Minimum Value c) Average Value d) Total Value e) Sin Value

*/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int data;
    struct node *next;

};

struct node *root=NULL,*temptr;

void maximum(struct node *a,int n){

    int max= a->data;
    while((a!= NULL)){
        if(max<(a->data)){
            max=a->data;
        }
        a = a->next;
    }
    printf("\n Maximum value: %d\n",max);
}

void minimum(struct node *a,int n){

    int min=a->next;

    while((a != NULL)){
            if(min>(a->data)){
                min=a->data;
            }
            a = a->next;
        }
    printf("\n Maximum value: %d\n",min);
}

void average(int array[],int n){

    float averageValue,sum= total(array,n);
    averageValue=sum/n;
    printf("\nAverage: %.2f\n",averageValue);
}


int total(struct node *a, int n){
    int sum=0;
    while(a!=NULL){
        sum=sum+(a->data);
        a=a->next;
    }
    return sum;
}

void sinValue(struct node *a, int n){
    printf("The sine values of each elements: \n");

    while(a!=NULL){
        printf("Sine value of %d is: %.2f\n", a->data,sin(a->data));
        a=a->next;
    }

}
int main(){

    int n, choice;
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
    int sum;
    while(1){
        printf("\n\n:::Menu:::\n");
        printf("1. Maximum Value\n");
        printf("2. Minimum Value\n");
        printf("3. Average Value\n");
        printf("4. Total Value\n");
        printf("5. Sin Value\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1: maximum(root,n);
                    break;
            case 2: minimum(root,n);
                    break;
            case 3: average(root,n);
                    break;
            case 4: sum = total(root,n);
                    printf("\nTotal value: %d\n",sum);
                    break;
            case 5: sinValue(root,n);
                    break;
            case 6: exit(0);
            default: printf("Enter valid input...");
        }
    }
  return 0;

}

