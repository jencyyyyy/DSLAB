/*
3. Deleting:
a) Delete Karim from a sorted array. b) Delete an Item from position 2.
*/

#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define STR 10
#define LEN 50

char a[STR][LEN];
int n;

int delValue(char array[][LEN],int n);
int delIndex(char array[][LEN],int n);
int main(){

    printf("Enter Size of array: ");
    scanf("%d",&n);

    printf("Enter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%s",a[i]);
    }

    int choice;

    while(1){
        printf("\n\n:::Menu:::\n");
        printf("1. Delete with Value\n");
        printf("2. Delete with index\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1: n = delValue(a,n);
                    break;
            case 2: n = delIndex(a,n);
                    break;
            case 3: exit(0);
            default: printf("Enter valid input...");
        }
    }

    return 0;
}

int delValue(char array[][LEN],int n){
        char value[LEN];
        int position=0;

        printf("Enter value to be deleted:");
        scanf("%s",value);

        for(int i=1;i<=n;i++){
            if(strcmp(array[i],value) == 0){
                position=i;
                break;
            }
        }

        if(position){
            for(int j=position;j<n;j++){
                strcpy(a[j], a[j+1]);
            }
        }

        n=n-1;

        printf("Elements: \n");
        for(int i=0;i<n;i++)
            printf(" %s ",array[i]);

        return n;
}

int delIndex(char array[][LEN],int n){

    int del;

    printf("Enter Index to be deleted: ");
    scanf("%d",&del);

    for(int i=0;i<n;i++){
        if(i== (del-1)){
                n= n-1;
                for(int j=i;j<n;j++){
                    strcpy(array[j],array[j+1]);
            }
        }
    }

    printf("Array: ");

    for(int j = 0;j<n;j++){
        printf(" %s ", array[j]);
    }

    return n;

}


