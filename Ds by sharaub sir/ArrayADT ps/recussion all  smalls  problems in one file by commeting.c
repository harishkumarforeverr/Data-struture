#include<stdio.h>
#include<conio.h>
void sum(int n){
    if(n==1)
        printf("1");
    else{
        sum(n/2);
        printf("%d",n%2);
    }
}
int main(){
     sum(43);
return 0;
}
