#include<stdio.h>
#define MAX 50
int lb,ub, a[MAX];
int partition(int a[], int lb,int ub){

    int pivot =a[lb];
    int start = lb;
    int end =ub;
    int temp;
    while(a[start]<=pivot){
        start++;
    }
    while(a[end]>pivot){
        end--;
    }
    if(start <end){
        temp =a[start];
        a[start]= a[end];
        a[end]=temp;
    }

    temp =a[lb];
    a[lb]= a[end];
    a[end]=temp;

    return end;
}
void quicksort(int a[25],int lb,int ub){
    int loc;
    if(lb<ub){
        loc = partition(a,lb,ub);
        quicksort(a,lb,loc-1);
        quicksort(a,loc+1,ub);
    }
}

int main(){
    int i, count, number[MAX];
    printf("Enter no. of elements to be sorted: ");
    scanf("%d",&count);
    printf("Enter %d elements: ", count);
    for(i=0;i<count;i++)
        scanf("%d",&number[i]);

    quicksort(number,0,count-1);
    printf("The Sorted Order is: ");
    for(i=0;i<count;i++)
        printf(" %d",number[i]);

return 0;
}
