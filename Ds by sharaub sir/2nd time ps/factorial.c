#include<stdio.h>
#include<conio.h>
int fact(int n){
 if(n==1)
    return 1;
 return (n*fact(n-1));
}
int main(){
 printf("\n\t output : %d ",fact(5));
getch();
return 0;
}
