/*
3. Deleting:
a) Delete Karim from a sorted array. b) Delete an Item from position 2.
*/

#include<stdio.h>
#include <stdlib.h>
#define MAX 100

int a[MAX],n;

int delValue(int array[],int n);

int main(){

    printf("Enter Size of array: ");
    scanf("%d",&n);

    printf("Enter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int choice, sum=0;

    while(1){
        printf("\n\n:::Menu:::\n");
        printf("1. Delete with Value\n");
      //  printf("2. Delete with index\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1: delValue(a,n);
                    break;
       //     case 2: delIndex(a,n);
     //               break;
            case 3: exit(0);
            default: printf("Enter valid input...");
        }
    }

    return 0;
}

int delValue(int array[],int n){
        int value,position=0;

        printf("Enter value to be deleted:");
        scanf("%d",&value);

        for(int i=1;i<=n;i++){
            if(array[i]==value){
                position=i;
                break;
            }
        }

        if(position){
            for(int j=position;j<n;j++){
                a[j] = a[j+1];
            }
        }

        n=n-1;

        printf("Elements: \n");
        for(int i=0;i<n;i++)
            printf(" %d ",array[i]);

        return n;
}
/*
int delIndex(int array[],int n){

}

*/
