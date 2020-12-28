#include<stdio.h>
#include<conio.h>
int main()
{
    int n;
    int fact(int);
    printf("\n\t enter a no ");
    scanf("%d",&n);
    printf("\n\t factorial of %d is %d ",n,fact(n));
    getch();
    return 0;
}
int fact(int n)
{
    if(n==1)
        return 1;
    return (n*fact(n-1));
}
