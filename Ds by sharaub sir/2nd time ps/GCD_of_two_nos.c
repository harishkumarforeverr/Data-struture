#include<stdio.h>
#include<conio.h>
int GCD(int a, int b){
 if(a==b)
    return a;
 if(a%b==0)
    return b;
 if(b%a==0)
    return a;
 if(a>b)
    return GCD(a%b,b);
 if(b>a)
    return GCD(a,b%a);
}
int main(){
 printf("\n\t output : %d ",GCD(105,91));
getch();
return 0;
}


