#include<stdio.h>
#include<conio.h>
void swap(char *a, char *b)
{
     char t=*a;
     *a=*b;
     *b=t;

}
void function(char *s, int i, int n)
{
    int j;
    if(i==n)
        printf("\n\t %s ",s);
    else
        for(j=i;j<=n;j++)
    {
        swap((s+i),(s+j));
        function(s,i+1,n);
        swap((s+i),(s+j));
    }
}
int main()
{
  char str[]="ABC";
  function(str,0,2);
}
