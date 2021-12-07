#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX];
void push();
void pop();
void display();
int top=-1,size;
int main(){

    printf("Enter Size of Stack: ");
    scanf("%d",&size);
    int choice;
    while(1){
        printf("\n  Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: push(size);
                    break;
            case 2: pop();
                    break;
            case 3: exit(0);
            default: printf("Enter accurate option...\n");

            }
        }
        return 0;

}
void push(){
    int data;

    if(top== size-1){
        printf("\nOverflow\n\n");
    }else{
        printf("\nEnter value: ");
        scanf("%d",&data);
        top++;
        stack[top] = data;
        printf("%d pushed\n\n",stack[top]);
    }
    display();
}

void pop(){

    if(top== -1){
        printf("\nUnderflow\n\n");

    }
    else{
        printf("\n%d POPED! \n\n",stack[top]);
        top--;
    }
    display();
}

void display(){
    if(top== -1){
        printf("\nEmpty stack\n\n");
    }
    printf("Stack elements: ");
    for(int i=0;i<=top;i++){
        printf(" %d ",stack[i]);
    }
}
