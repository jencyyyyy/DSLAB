//11. Delete an element from a queue.

#include<stdlib.h>
#include<conio.h>
# include<stdio.h>
# define MAX 50
void enQueue(int);
void deQueue();
void display();
int queue[MAX], front=-1,rear=-1;

int main(){
    int value,choice;
     while(1){
        printf("\nMENU\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the value to be insert: ");
                    scanf("%d",&value);
                    enQueue(value);
                    break;
            case 2: deQueue();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
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
void deQueue(){
   if(front == rear){
      printf("\nQueue is Empty!!! Deletion is not possible!!!");
   }else{
      printf("\nDeleted : %d", queue[front]);
      front++;
      if(front == rear){
        front = rear = -1;
      }
   }
}
void display(){
   if(rear == -1){
      printf("\nQueue is Empty!!!\n");
   }else{
      printf("\nQueue elements are:\n");
      for(int i=front; i<=rear; i++)
	  printf("%d\t",queue[i]);
   }
}
