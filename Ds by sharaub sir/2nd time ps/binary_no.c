#include<stdio.h>
#include<conio.h>
void bin(char A[], int n){
    static int count=0;
 if(n<1)
    printf("\n\t%s",A);
 else{
    A[n-1]='0';
    bin(n-1,A);
    A[n-1]='1';
    bin(A,n-1);
 }
 count=count+1;
 if(count==20)
    return ;
}
int main(){
char A[10];
A[10]='\0';
bin(A,10);
getch();
return 0;
}


