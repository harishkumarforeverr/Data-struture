#include<stdio.h>
#include<conio.h>
void TowerHonio(int n, char beg, char mid, char end)
{
    if(n>=1)
    {
        TowerHonio(n-1,beg,end,mid);
        printf("\n\t %c to %c",beg,end);
        TowerHonio(n-1,mid,beg,end);
    }
}
int main()
{
 char a='a';
 char b='b';
 char c='c';
 TowerHonio(3,a,b,c);
}
