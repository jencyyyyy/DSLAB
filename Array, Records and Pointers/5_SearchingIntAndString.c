/*5. Searching:
a) Search for 77 using Linear/Binary Search. b) Search for Karim using Linear/Binary Search.*/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10
#define LEN 50
int a[SIZE], narray;
char string[SIZE][LEN];
int nstring;

void lsrcInt(int a[],int narray);
void bsrcInt(int a[], int narray);
void lsrcString(char string[][LEN],int nstring);
void bsrcString(char string[][LEN], int nstring);

int main(){

    printf("Enter number of elements: ");
    scanf("%d", &narray);

    printf("Enter %d integers in ascending Order: ", narray);
    for (int c = 0; c < narray; c++)
        scanf("%d", &a[c]);

    printf("Enter Size of String array: ");
    scanf("%d",&nstring);

    printf("Enter Strings of the array: \n");
    for(int i=0;i<nstring;i++)
        scanf("%s",string[i]);
    int choice;

    while(1){
        printf("\n\n:::Menu:::\n");
        printf(" Searching Integer\n");
        printf("1. Linear\n");
        printf("2. Binary\n");
        printf(" Searching String \n");
        printf("3. Linear\n");
        printf("4. Binary\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: lsrcInt(a,narray);
                    break;
            case 2: bsrcInt(a,narray);
                    break;
            case 3: lsrcString(string,nstring);
                    break;
            case 4: bsrcString(string,nstring);
                    break;
            case 5: exit(0);
            default: printf("Enter valid input...");
        }
    }
    return 0;
}

void lsrcInt(int a[],int narray){
    int  item, i,indexValue,c=0;
    printf("\n Enter search item: ");
    scanf("%d", &item);
    for(int i=0;i<narray;i++){
        if(a[i]== item){
            c=1;
            indexValue=i;
            break;
        }
    }
    if(c){
        printf("\n Found at %d",indexValue+1);
    }else{
        printf("\n Not found");
    }
}

void bsrcInt(int a[], int narray){

    int search,first,last,middle;
    printf("Enter the integer data to be searched: ");
    scanf("%d", &search);
    first = 0;
    last = narray - 1;
    middle = (first+last)/2;

    while (first <= last) {
        if (a[middle] < search){
            first = middle + 1;
        }else if (a[middle] == search) {
            printf("%d found at location %d.\n", search, middle+1);
            break;
        }else{
            last = middle - 1;
        }
        middle = (first + last)/2;
    }
    if (first > last){
        printf("\nNot found! %d isn't present in the list.\n", search);
    }
}

void lsrcString(char string[][LEN], int nstring){
    char item[LEN];
    int indexValue;
    int c=0;
    printf("\n Enter search item: ");
    scanf("%s", item);
    for(int i=0;i<nstring;i++){
        if(strcmp(string[i], item)==0){
            c=1;
            indexValue=i;
            break;
        }
    }
    if(c){
        printf("\n Found at %d",indexValue+1);
    }else{
        printf("\n Not found");
    }
}

void bsrcString(char string[][LEN], int nstring){
    char search[LEN];
    int first,last,middle;
    printf("Enter the String to be searched: ");
    scanf("%s", search);
    first = 0;
    last = nstring - 1;
    middle = (first+last)/2;
    while (first <= last) {
        if (strcmp(string[middle], search)<0){
            first = middle + 1;
        }else if (strcmp(string[middle], search) == 0) {
            printf("%s found at location %d.\n", search, middle+1);
            break;
        }else{
            last = middle - 1;
        }
        middle = (first + last)/2;
    }

    if (first > last){
        printf("\nNot found! %s isn't present in the list.\n", search);
    }

}

