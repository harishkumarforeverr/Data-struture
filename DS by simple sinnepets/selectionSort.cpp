#include<iostream>
using namespace std;
void selectionSort(int arr[], int n){
     for(int i=0;i<n-1;i++){
        int min=i;
         for(int j=i+1;j<n;j++){
            if(arr[min]>arr[j])
                min=j;
         }
         if(min!=i){
            int temp=arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
         }
     }
}
int main(){
 int n=7;
 int arr[7]={9,0,6,3,4,8,7};
 printf("\n\t before Sorting : ");
 for(int i=0;i<n;i++){
    cout<<" "<<arr[i];
 }
 selectionSort(arr,n);
 printf("\n\t after Sorting : ");
 for(int i=0;i<n;i++){
    cout<<" "<<arr[i];
 }
 return 0;
}
