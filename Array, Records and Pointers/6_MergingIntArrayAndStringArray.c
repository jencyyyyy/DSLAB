/*6. Merging:
a) Add two integer type arrays. b) Add two character type arrays.
*/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10
#define LEN 50

int a[SIZE], na;
int b[SIZE], nb;

char stringA[SIZE][LEN];
char stringB[SIZE][LEN];

int strAsize, strBsize;

void mergeIntArray(int a[],int b[],int na,int nb);
void mergeStringArray(char stringA[][LEN],char stringB[][LEN],int strAsize,int strBsize);


int main(){

    printf("Enter size of 1st array: ");
    scanf("%d", &na);

    printf("Enter %d integers: ", na);
    for (int c = 0; c < na; c++)
        scanf("%d", &a[c]);

    printf("Enter size of 2nd array: ");
    scanf("%d", &nb);

    printf("Enter %d integers: ", na);
    for (int c = 0; c < nb; c++)
        scanf("%d", &b[c]);

    printf("Enter Size of 1st String array: ");
    scanf("%d",&strAsize);

    printf("Enter Strings of the array: \n");
    for(int i=0;i<strAsize;i++){
        scanf("%s",stringA[i]);
    }


    printf("Enter Size of 2nd String array: ");
    scanf("%d",&strBsize);

    printf("Enter Strings of the array: \n");
    for(int i=0;i<strBsize;i++){
        scanf("%s",stringB[i]);
    }
    int choice;
    while(1){
        printf("\n\n:::Menu:::\n");
        printf("1. mergeIntArray\n");
        printf("2. mergeStringArray\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1: mergeIntArray(a,b,na,nb);
                    break;
            case 2: mergeStringArray(stringA,stringB,strAsize,strBsize);
                    break;
            case 3: exit(0);
            default: printf("Enter valid input...");
        }
    }
    return 0;
}

void mergeIntArray(int a[],int b[],int na,int nb){
    int l,j;
    int s = na+nb;
    int C[s];

    for(int k=0;k<na;k++){
        C[k]= a[k];
    }

    for( l=0,j=na;l<na,j<s;l++,j++){
        C[j]= b[l];
    }

    printf("\nMerged array: {");
    for(int i=0;i<s;i++){
        printf(" %d ",C[i]);
    }
    printf("}");

}

void mergeStringArray(char stringA[][LEN],char stringB[][LEN],int strAsize,int strBsize){
    int l,j;
    int s = strAsize+strBsize;
    char C[s][LEN];

    for(int k=0;k<strAsize;k++){
       strcpy(C[k],stringA[k]);
    }

    for( l=0,j=strAsize;l<strAsize,j<s;l++,j++){
        strcpy(C[j], stringB[l]);
    }

    printf("\nMerged String array: {");
    for(int i=0;i<s;i++){
        printf(" %s ",C[i]);
    }
    printf("}");
}

