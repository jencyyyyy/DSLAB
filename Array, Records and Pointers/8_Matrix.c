/*8. Matrix: Addition/Subtraction/Multiplication of two matrices.*/

#include<stdio.h>
#include<stdlib.h>

#define R 10
#define C 10
int a[R][C],b[R][C];
int arow,acol,brow,bcol;

void enterValues(int v);
int checkAddSub(int arow,int acol,int brow,int bcol);
void addition(int a[R][C],int b[R][C],int arow,int acol,int brow,int bcol);
void subtraction(int a[R][C],int b[R][C],int arow,int acol,int brow,int bcol);
void multiplication(int a[R][C],int b[R][C],int arow,int acol,int brow,int bcol);

int main(){

    printf("Enter no. of rows and columns of 1st matrix: ");
    scanf("%d %d",&arow,&acol);

    printf("\nEnter elements of 1st matrix:\n");
    for (int i = 0; i < arow; i++){
        for (int j = 0; j < acol; j++) {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\n\nEnter no. of rows and columns of 2nd matrix: ");
    scanf("%d %d",&brow,&bcol);

    printf("\n\nEnter elements of 2nd matrix:\n");
    for (int i = 0; i < brow; i++){
        for (int j = 0; j < bcol; j++) {
            printf("Enter element b%d%d: ", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    }

    int choice;

    while(1){
        printf("\n\n:::Menu:::\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1: addition(a,b,arow,acol,brow,bcol);
                    break;
            case 2: subtraction(a,b,arow,acol,brow,bcol);
                    break;
            case 3: multiplication(a,b,arow,acol,brow,bcol);
                    break;
            case 4: exit(0);
            default: printf("Enter valid input...");
        }
    }

    return 0;
}

void enterValues(int v){
    printf("\n\n:::RE-ENTER all values:::\n");
    printf("Enter no. of rows and columns of 1st matrix: ");
    scanf("%d %d",&arow,&acol);

    printf("\nEnter elements of 1st matrix:\n");
    for (int i = 0; i < arow; i++){
        for (int j = 0; j < acol; j++) {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
    printf("\n\nEnter no. of rows and columns of 2nd matrix: ");
    scanf("%d %d",&brow,&bcol);
    printf("\n\nEnter elements of 2nd matrix:\n");
    for (int i = 0; i < brow; i++){
        for (int j = 0; j < bcol; j++) {
            printf("Enter element b%d%d: ", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    }
    switch(v){
        case 1: addition(a,b,arow,acol,brow,bcol);
                break;
        case 2: subtraction(a,b,arow,acol,brow,bcol);
                break;
        case 3: multiplication(a,b,arow,acol,brow,bcol);
                break;
    }


}
int checkAddSub(int arow,int acol,int brow,int bcol){

    if (arow != brow || acol != bcol) {
        printf("\nOrder of two matrices is not same. Enter matrix again.\n ");
        return 0;
   }else{
        return 1;
   }


}
void addition(int a[R][C],int b[R][C],int arow,int acol,int brow,int bcol){

    int check = checkAddSub(arow,acol,brow,bcol);
    if(check){
        int sum[arow][acol];
            for (int i = 0; i < arow; i++){
            for (int j = 0; j < acol; j++) {
                sum[i][j] = a[i][j] + b[i][j];
            }
        }

        printf("\nSum of two matrices: \n");
        for (int i = 0; i < arow; i++){
            for (int j = 0; j < acol; j++) {
                printf("%d   ", sum[i][j]);
            }
            printf("\n");
        }
    }
    else{
        enterValues(1);
    }


}
void subtraction(int a[R][C],int b[R][C],int arow,int acol,int brow,int bcol){

   int check = checkAddSub(arow,acol,brow,bcol);
    if(check){
    int dif[arow][acol];
    for (int i = 0; i < arow; ++i){
        for (int j = 0; j < acol; ++j) {
            dif[i][j] = a[i][j] - b[i][j];
        }
     }

    printf("\nSum of two matrices: \n");
    for (int i = 0; i < arow; ++i){
        for (int j = 0; j < acol; ++j) {
            printf("%d   ", dif[i][j]);
        }
        printf("\n");
    }
    }else{
        enterValues(2);
    }


}
void multiplication(int a[R][C],int b[R][C],int arow,int acol,int brow,int bcol){

    int c[R][C];

    if(acol != brow){
        enterValues(3);
    }else{
        for(int i=0;i<arow;i++){
            for(int j=0;j<bcol;j++){
                c[i][j]=0;
                for(int k=0;k<acol;k++){
                    c[i][j]+=a[i][k]*b[k][j];
                }
            }
        }
    }

    printf("\n\nRequired product:\n");
    for(int i=0;i<arow;i++){
        for(int j=0;j<bcol;j++){
            printf(" %d ",c[i][j]);
        }
        printf("\n");
    }
}
