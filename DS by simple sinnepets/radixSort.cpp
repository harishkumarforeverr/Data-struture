#include<iostream>
using namespace std;
int getMaxNo(int arr[], int n){
    int max=0;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[max]){
            max=i;
        }
    }
    return arr[max];
}
void countingSort(int input_array[],int n,int div){
  int counting_array[10]={0};
  int output_array[n]={0};
  for(int i=0;i<n;i++){
    counting_array[(input_array[i]/div)%10]++;
  }

  for(int i=1;i<10;i++){
    counting_array[i]=counting_array[i]+counting_array[i-1];
  }

  for(int i=n-1;i>=0;i--){
    output_array[counting_array[(input_array[i]/div)%10]-1]=input_array[i];
    counting_array[(input_array[i]/div)%10]--;
  }
  for(int i=0;i<n;i++){
    input_array[i]=output_array[i];
  }
}
void radixSort(int arr[],int n){
  int max=getMaxNo(arr,n);
  for(int div=1;max/div>0;div*=10)
    countingSort(arr,n,div);
}

int main(){
 int arr[11]={90,0,60,33,400,88,18,40,49,66,913};
 int n=11;
 printf("\n\t before Sorting : ");
 for(int i=0;i<n;i++){
    cout<<" "<<arr[i];
 }
 radixSort(arr,11);
 printf("\n\t after Sorting : ");
 for(int i=0;i<n;i++){
    cout<<" "<<arr[i];
 }
 return 0;
}
