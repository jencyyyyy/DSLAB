/*
1. Traversing: carry out the following operations on an Array
a) Maximum Value b) Minimum Value c) Average Value d) Total Value e) Sin Value
*/

#include<stdio.h>
#include <stdlib.h>
#include<math.h>
#define MAX 100
int a[MAX],n;
void maximum(int a[],int n);
void minimum(int a[],int n);
void average(int a[],int n);
int total(int a[], int n);
void sinValue(int a[],int n);

int main(){
    printf("Enter Size of array: ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);}

    int choice, sum=0;

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
            case 1: maximum(a,n);
                    break;
            case 2: minimum(a,n);
                    break;
            case 3: average(a,n);
                    break;
            case 4: sum = total(a,n);
                    printf("\nTotal value: %d\n",sum);
                    break;
            case 5: sinValue(a,n);
                    break;
            case 6: exit(0);
            default: printf("Enter valid input...");
        }
    }
    return 0;
}

void maximum(int a[],int n){
    int max=a[0];
    for(int i=0;i<n;i++){
        if(max<a[i])
            max=a[i];
    }
    printf("\n Maximum value: %d\n",max);
}

void minimum(int array[],int n){
    int min=a[0];
    for(int i=0;i<n;i++){
        if(min>a[i])
            min=a[i];
        }
    printf("\n Minimum value: %d\n",min);
}

void average(int array[],int n){
    float averageValue,sum= total(array,n);
    averageValue=sum/n;
    printf("\nAverage: %.2f\n",averageValue);
}

int total(int a[], int n){
    int sum=0;
    for(int i= 0;i<n;i++)
        sum= sum + a[i];
    return sum;
}

void sinValue(int array[],int n){
    float sinValues[n];
    for(int i=0;i<n;i++){
        sinValues[i] = sin(a[i]);}
    printf("The sine values of each elements: \n");
    for(int i=0;i<n;i++)
        printf("Sine value of %d is: %f\n", a[i],sinValues[i]);
}

