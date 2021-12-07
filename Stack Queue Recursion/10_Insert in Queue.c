//10. Insert an element into a queue.

#include<stdlib.h>
#include<conio.h>
# include<stdio.h>
# define MAX 50
void enQueue(int);
int queue[MAX], front=-1,rear=-1;
int main(){
    int value,choice;
     while(1){
        printf("\nMENU\n");
        printf("1. Insertion\n2. Display\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the value to be insert: ");
                    scanf("%d",&value);
                    enQueue(value);
                    break;
            case 2: display();
                    break;
            case 3: exit(0);
            default: printf("\nInvalid input! Try again!!!");
        }
     }
    return 0;
}

void enQueue(int value){
   if(rear == MAX-1)
      printf("\nQueue is Full!!! Insertion is not possible!!!\n");
   else{
      if(front == -1){
            front = 0;
      }
    rear++;
      queue[rear] = value;
      printf("\nInsertion success!!!");
   }
}
void display(){
   if(rear == -1)
      printf("\nQueue is Empty!!!\n");
   else{
      int i;
      printf("\nQueue elements are:\n");
      for(i=front; i<=rear; i++)
	  printf("%d\t",queue[i]);
   }
}
