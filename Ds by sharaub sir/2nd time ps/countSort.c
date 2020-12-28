#include<stdio.h>
#include<conio.h>
int main(){
    int B[15],k=10,n=10;
    int A[]={9,0,6,3,4,8,8,4,4,6};
    printf("\n\t stage-1 : ");
    for(int i=0;i<n;i++)
    printf(" %d ",A[i]);
    countMerge(A,n,B,k);
    printf("\n\t stage-2 : ");
    for(int i=0;i<n;i++)
    printf(" %d ",B[i]);
    getch();
    return 0;
}
void countMerge(int a[],int n,int b[],int k){
    int c[k];
    for(int i=0;i<n;i++)
    c[i]=0;
    for(int i=0;i<n;i++)
    c[a[i]]=c[a[i]]+1;
    for(int i=1;i<n;i++)
    c[i]=c[i]+c[i-1];
    for(int i=0;i<n;i++){
        b[c[a[i]]-1]=a[i];
        c[a[i]]=c[a[i]]-1;
    }
}
