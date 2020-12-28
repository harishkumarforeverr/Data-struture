#include<stdio.h>
#include<conio.h>
void mergeSortAlgorithm(int arr[],int beg,int mid,int end){
    int i=beg,j=mid+1,index=beg,temp[10];
    while((i<=mid)&&(j<=end)){
        if(arr[i]<arr[j]){
            temp[index]=arr[i];
            index++;
            i++;
        }
        else{
            temp[index]=arr[j];
            index++;
            j++;
        }
    }
    if(i>mid){
        while(j<=end){
            temp[index]=arr[j];
            index++;
            j++;
        }
    }
    else{
        while(i<=mid){
            temp[index]=arr[i];
            index++;
            i++;
        }
    }
    for(int i=beg;i<=end;i++){
        arr[i]=temp[i];
    }
}
void mergeSort(int arr[],int beg ,int end){
   int mid;
   if(beg<end){
    mid=(beg+end)/2;
    mergeSort(arr,beg,mid);
    mergeSort(arr,mid+1,end);
    mergeSortAlgorithm(arr,beg,mid,end);
   }
}
int main(){
  int arr[]={9,0,6,3,4,8,8,4,4,6};
  int n=sizeof(arr)/sizeof(arr[0]);
  printf("\n\t array elements before sorting : ");
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
  mergeSort(arr,0,n-1);
  printf("\n\t array elements before sorting : ");
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
}
