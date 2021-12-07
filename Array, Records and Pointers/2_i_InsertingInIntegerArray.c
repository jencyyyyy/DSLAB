/*
2. Inserting: Insert
a) 54 to a sorted array. b) Rahim to a sorted array. c) 99 to position 5. d) Karim to position 5.
*/
#include<stdio.h>
#include <stdlib.h>
#define MAX 100
int a[MAX],n;
int value(int a[], int n);
int index(int a[], int n);
int main(){

    printf("Enter Size of array: ");
    scanf("%d",&n);

    printf("Enter Sorted array elements: ");

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int choice;

    while(1){
        printf("\n\n:::Menu:::\n");
        printf("1. Insert data with value\n");
        printf("2. Insert data with Index\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1: n = value(a,n);
                    break;
            case 2: n= index(a,n);
                    break;
            case 3: exit(0);
            default: printf("Enter valid input...");
        }
    }

    return 0;
}
int value(int a[], int n){
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
    return n;
}



int index(int a[], int n){

    int indexValue,item;

    printf("\nEnter index no. to insert the data: ");
    scanf("%d",&indexValue);
    printf("Enter data to be inserted: ");
    scanf("%d",&item);

    for(int j=n+1;j>=indexValue;j--){
            a[j] = a[j-1];
    }

    a[indexValue] = item;
    n=n+1;

    printf("\n\nFinal Array elements: ");

    for(int i=0;i<n;i++){
        printf(" %d ",a[i]);
    }
    return n;
}
