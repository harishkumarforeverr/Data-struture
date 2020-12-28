#include<stdio.h>
#include<conio.h>
void bin(int n, char A[])
{
    if(n<1)
        printf("\n\t %s",A);
    else
    {
        A[n-1]='0';
        bin(n-1,A);
        A[n-1]='1';
        bin(n-1,A);

    }
}
int main()
{
    char str[10];
    str[10]='\0';
    bin(10,str);
}
