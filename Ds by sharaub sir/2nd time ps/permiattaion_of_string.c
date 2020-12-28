#include<stdio.h>
#include<conio.h>
void perm(char *str, int i, int n){
    if(i==n)
        printf("\n\t %s",str);
    else
    for(int j=i;j<=n;j++){
        swap(str+i,str+j);
        perm(str,i+1,n);
        swap(str+i,str+j);
    }
}
void swap(char *ch1, char *ch2){
    char t=*ch1;
    *ch1=*ch2;
    *ch2=t;
}
int main(){
  char str[]="abc";
  perm(str,0,2);
getch();
return 0;
}
