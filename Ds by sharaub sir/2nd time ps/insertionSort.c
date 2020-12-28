#include<stdio.h>
#include<conio.h>
void insertionSort(int arr[], int n){
    for(int i=1;i<n;i++){
        int j=i-1;
        int data=arr[i];
        while(j>=0&&arr[j]>data){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=data;
    }

}
int main(){
    int arr[]={9,0,6,3,4,8};
    printf("\n\t array values before sorting : ");
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
        printf(" %d",arr[i]);
    insertionSort(arr,sizeof(arr)/sizeof(arr[0]));
    printf("\n\t array values after sorting : ");
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    printf(" %d",arr[i]);
getch();
return 0;
}
