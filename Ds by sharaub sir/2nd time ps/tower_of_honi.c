#include<stdio.h>
#include<conio.h>
void TOH(int n, char *A, char *B, char *C){
  if(n>=1){
    TOH(n-1,A,C,B);
    printf("\n\t %c -- %c ",*A,*C);
    TOH(n-1,B,A,C);
  }
}
int main(){
  TOH(3,"a","b","c");
getch();
return 0;
}

