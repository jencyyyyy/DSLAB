/*4. Sorting:
a) Sort integer data using Bubble sort. b) Sort string data using Bubble sort.*/
/* Bubble sort code */
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10
#define LEN 50


int a[SIZE], narray;
char string[SIZE][LEN];
int nstring;

void bubbleSort( int array[],int n);
void stringBubbleSort( char array[][LEN],int n);
int main(){

    printf("Enter number of elements: ");
    scanf("%d", &narray);

    printf("Enter %d integers: ", narray);
    for (int c = 0; c < narray; c++)
        scanf("%d", &a[c]);

    printf("Enter Size of String array: ");
    scanf("%d",&nstring);

    printf("Enter Strings of the array: \n");

    for(int i=0;i<nstring;i++){
        scanf("%s",string[i]);
    }
    bubbleSort(a,narray);
    stringBubbleSort(string,nstring);
    return 0;
}

void bubbleSort( int array[],int n){
    int c, d, swap;
    for (int c = 0 ; c < n - 1; c++){
        for (int d = 0 ; d < n - c - 1; d++){
            if (array[d] > array[d+1]){
                swap       = array[d];
                array[d]   = array[d+1];
                array[d+1] = swap;
            }
        }
    }
    printf("\n\nSorted list in ascending order:\n");

    for (c = 0; c < n; c++)
        printf("%d ", array[c]);


}
void stringBubbleSort( char array[][LEN],int n){
    int c, d;
    char swap[LEN];
    for (c = 0 ; c < n - 1; c++){
        for (d = 0 ; d < n - c - 1; d++){
           if(strcmp(array[d],array[d+1])>0){
                strcpy(swap,array[d]);
                strcpy(array[d],array[d+1]);
                strcpy(array[d+1],swap);
            }
        }
    }
    printf("\n\nSorted list in ascending order:\n");
    for (c = 0; c < n; c++)
        printf(" %s ", array[c]);
}
