#include<iostream>
using namespace std;
void insertionSort(int arr[], int n){
  for(int i=1;i<n;i++){
    int temp=arr[i];
    int j=i-1;
     while(j>=0&&arr[j]>temp){
        arr[j+1]=arr[j];
        j--;
     }
    if(i!=j){
            arr[j+1]=temp;
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
 insertionSort(arr,n);
 printf("\n\t after Sorting : ");
 for(int i=0;i<n;i++){
    cout<<" "<<arr[i];
 }
 return 0;
}
