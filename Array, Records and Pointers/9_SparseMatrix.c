/*9. Sparse Matrix: Store the element of a Triangular matrix A into a 1D array B and
locate the elements A32 in the array B.*/

#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#define R 10
#define C 10
int A[R][C], B[R];
int arow,acol,brow;

int main(){
    int i,j;
    printf("Enter no. of rows: ");
    scanf("%d",&arow);

    printf("Enter no. columns: ");
    scanf("%d",&acol);

    printf("\nEnter elements of matrix:\n");
    for (i = 0; i < arow; i++){
        for (j = 0; j < acol; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    brow=0;
    for (i = 0; i < arow; i++){
        for (j = 0; j < acol; j++) {
            if(A[i][j] !=0){
                B[brow]=A[i][j];
                brow++;
            }
        }
    }

     printf("\n Given Sparse Matrix\n");
    for(i=0; i<arow; i++){
        for(j=0; j<acol; j++){
            printf(" %d ", A[i][j]);
        }
        printf("\n");
    }

    printf("\n 1D array (Row wise)\n");
    for(int i=0; i<brow; i++){
        printf(" %d ", B[i]);
    }
    int r,c;
    printf("\n\nThe location of the element with array row and column(where 1 <= r, c <= N and r >= c):  ");
    scanf("%d %d",&r,&c);

    for( i = 0; i<brow; i++){
        if(B[i]==A[r][c]){
            printf("\n A[%d][%d] element is found at B[%d]\n", r, c, i);
            break;
        }
    }
    if(i == brow){
        printf("\n A[%d][%d] element is not found at B\n", r, c);
    }
    return 0;
    /*float l =(((r-1) *(r-2))/2 + c -1);

    int result = ceil(l);
    printf("\n\n%d is at index: [%d] in 1D array",B[result],result);

*/

    return 0;
}


