#include<stdio.h>
#include<conio.h>
int fib(int n){
 if(n==1||n==2)
    return 1;
 return (fib(n-1)+fib(n-2));
}
int main(){
 printf("output : %d ",fib(6));
getch();
return 0;
}


