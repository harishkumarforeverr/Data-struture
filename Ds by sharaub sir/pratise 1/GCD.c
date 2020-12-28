#include<stdio.h>
#include<conio.h>
int GCD(int a, int b)
{
    if(a==b)
        return a;
    else if(a%b==0)
        return b;
    else if(b%a==0)
        return b;
    else if(a>b)
        GCD(a%b,b);
    else if(b>a)
    GCD(a,b%a);
}
int main()
{
    printf("\n\t output =  %d",GCD(105,91));
    getch();
    return 0;
}
