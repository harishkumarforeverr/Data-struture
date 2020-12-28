#include<stdio.h>
#include<conio.h>
int selectionSort(int arr[], int index, int n){
     int data=arr[index];
     int loc=index;
     for(int i=index+1;i<n;i++){
        if(data>arr[i]){
            data=arr[i];
            loc=i;
        }
     }
     return loc;
}
int main(){
    int index,temp;
    int arr[]={9,0,6,3,4,8};
    printf("\n\t array values before sorting : ");
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    printf(" %d",arr[i]);
    for(int i=0;i<sizeof(arr)/sizeof(arr[0])-1;i++){
        index=selectionSort(arr,i,sizeof(arr)/sizeof(arr[0]));
        temp=arr[i];
        arr[i]=arr[index];
        arr[index]=temp;
    }

    printf("\n\t array values after sorting : ");
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    printf(" %d",arr[i]);
getch();
return 0;
}
