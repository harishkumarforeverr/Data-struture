#include<stdio.h>
#include<conio.h>
int sum(int n){
 if(n==1)
    return 1;
 return n+sum(n-1);
}
int main(){
 printf("\n\t sum of %d is %d ",4,sum(4));
getch();
return 0;
}
