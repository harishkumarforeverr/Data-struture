#include<stdio.h>
#include<conio.h>
void sortSort(int arr[],int beg,int end, int b[]){
    int c[10];
    for(int i=0;i<10;i++){
        c[i]=0;
        b[i]=0;
    }
    for(int i=0;i<10;i++){
        c[arr[i]]=c[arr[i]]+1;
    }
    for(int i=1;i<10;i++){
        c[i]=c[i]+c[i-1];
    }
    for(int i=0;i<10;i++){
        b[c[arr[i]]-1]=arr[i];
        c[arr[i]]--;
    }
}
int main(){
  int arr[]={9,0,6,3,4,8,8,4,4,6};
  int n=sizeof(arr)/sizeof(arr[0]);
  printf("\n\t array elements before sorting : ");
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
  int B[n];
  sortSort(arr,0,n,B);
  printf("\n\t array elements before sorting : ");
  for(int i=0;i<n;i++){
    printf("%d ",B[i]);
  }
}
