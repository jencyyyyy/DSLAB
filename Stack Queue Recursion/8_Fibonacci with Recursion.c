#include<stdio.h>

int Fibonacci(int);

int main()
{
   int n, i = 0, c;
    printf("Enter data: ");
   scanf("%d",&n);

   printf("Fibonacci series\n");

   for ( c = 1 ; c <= n ; c++ ){
      printf("%d ", Fibonacci(i));
      i++;
   }

   return 0;
}

int Fibonacci(int n){
   if ( n <= 1 )
      return n;
   else
      return ( Fibonacci(n-1) + Fibonacci(n-2) );
}
