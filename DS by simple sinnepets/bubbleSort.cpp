#include<iostream>
using namespace std;
void bubbleSort(int arr[], int n){
   for(int i=0;i<n-1;i++){
      for(int j=0;j<n-1-i;j++){
        if(arr[j]>arr[j+1]){
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
      }
   }
}
int main(){
    int arr[7]={9,0,6,3,4,8,7};
    cout<<"\n\t before sorting : ";
    for(int i=0;i<7;i++){
      cout<<arr[i]<<" ";
    }
    bubbleSort(arr, 7);
    cout<<"\n\t after sorting : ";
    for(int i=0;i<7;i++){
      cout<<arr[i]<<" ";
    }

 return 0;
}
