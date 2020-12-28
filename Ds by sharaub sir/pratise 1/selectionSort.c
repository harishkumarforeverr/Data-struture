#include<stdio.h>
#include<conio.h>
int selectionSort(int [],int,int);
int main(){
     int arr[]={9,0,6,3,4,8,8,4,4,6};
     int n=sizeof(arr)/sizeof(int);
     printf("\n\t array values before sorting :");
     for(int i=0;i<n;i++)
     printf(" %d ",arr[i]);
     for(int i=0;i<n-1;i++) { //i wrote n-1 becoz at end of the loop one elements(last element) will occupy its corrrect position so i wrote n-1
         int min=selectionSort(arr,i,n);
         int temp=arr[i];
         arr[i]=arr[min];
         arr[min]=temp;
     }
     printf("\n\t array values after sorting :");
     for(int i=0;i<n;i++)
     printf(" %d ",arr[i]);
}
int selectionSort(int arr[],int index, int n){
            int min=arr[index];
            int loc=index;
            for(int i=index+1;i<n;i++){
                if(min>arr[i]){
                    min=arr[i];
                    loc=i;
                }
            }
            return loc;
}
