#include<stdio.h>
#include<conio.h>
int main()
{
    int n;
    int fib(int);
    printf("\n\t enter a no  = ");
    scanf("%d",&n);
    printf("\n\t values of %d is %d",n,fib(n));
}
int fib(int n)
{
    if(n==1||n==2)
        return 1;
    return (fib(n-1)+fib(n-2));
}
