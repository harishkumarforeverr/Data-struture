#include<stdio.h>
#include<conio.h>
// insertionSort program
void insertionSort(int [], int,int,int);
int main(){
     int arr[]={9,0,6,3,4,8,8,4,4,6};
     int n=sizeof(arr)/sizeof(int);
     printf("\n\t array values before sorting :");
     for(int i=0;i<n;i++)
     printf(" %d ",arr[i]);
     for(int i=0;i<n;i++){
     int temp=arr[i];
     insertionSort(arr,i,n,temp);
     }
     printf("\n\t array values after sorting :");
     for(int i=0;i<n;i++)
     printf(" %d ",arr[i]);
}
void insertionSort(int arr[],int index,int n,int temp)
{
     for(int i=index-1;i>=0&&arr[i]>temp;i--){
        arr[i+1]=arr[i];
        arr[i]=temp;
     }

}
