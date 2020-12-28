#include<stdio.h>
#include<conio.h>
void mergeSortAlogorthim(int arr[],int beg,int mid,int end){
       int i,j,temp[10],index;
       i=beg;
       j=mid+1;
       index=beg;
       while(i<=mid&&j<=end){
        if(arr[i]<arr[j]){
            temp[index]=arr[i];
            i++;
            index++;
        }
        else{
            temp[index]=arr[j];
            j++;
            index++;
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
void mergeSort(int arr[], int beg, int end){
    int mid;
    if(beg<end){
        mid=(beg+end)/2;
        mergeSort(arr,beg,mid);
        mergeSort(arr,mid+1,end);
        mergeSortAlogorthim(arr,beg,mid,end);
    }
}
int main(){
    int arr[]={9,0,6,3,4,8};
    printf("\n\t array values before sorting : ");
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
        printf(" %d",arr[i]);
    mergeSort(arr,0,sizeof(arr)/sizeof(arr[0]));
    printf("\n\t array values after sorting : ");
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    printf(" %d",arr[i]);
getch();
return 0;
}
