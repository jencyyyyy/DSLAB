/*7. Copy elements of a 2D array into a 1D/linear array and print the elements of
group 3 from the 1D array.
*/

#include<stdio.h>
#define R 10
#define C 10

int main(){

    int a[R][C], b[R];
    int r, c;

    printf("Enter the no. of rows of 2D array: ");
    scanf("%d",&r);

    printf("Enter the no. of Columns of 2D array: ");
    scanf("%d",&c);

    printf("Enter the data of 2D array: \n");


    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&a[i][j]);
        }
    }


    printf("\n\nThe data of 2D array:\n");


    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf(" %d ",a[i][j]);
        }
        printf("\n");
    }

    int s = r*c;

    for(int p=0;p<r;p++){
        for(int q=0;q<c;q++){
            b[p*c+q]=a[p][q];
        }
    }

    printf("The 1D array: \n");

    for(int i=0;i<s;i++){
        printf(" %d ", b[i]);
    }

    return 0;
}
