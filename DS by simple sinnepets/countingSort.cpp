#include<iostream>
using namespace std;
void countingSort(int input_array[], int range , int size){
  int count_array[range]={0};
  int output_array[size]={0};
  // counting the elements
  for(int i=0;i<size;i++){
    count_array[input_array[i]]++;
  }

  // c.c.f
  for(int i=1;i<range;i++){
    count_array[i]=count_array[i]+count_array[i-1];
  }

  // inserting the values
  for(int i=0;i<size;i++){
    output_array[--count_array[input_array[i]]]=input_array[i];
  }
  for(int i=0;i<size;i++){
    input_array[i]=output_array[i];
  }
}
int main(){
 int n=7;
 int arr[7]={9,0,6,3,4,8,7};
 printf("\n\t before Sorting : ");
 for(int i=0;i<n;i++){
    cout<<" "<<arr[i];
 }
 countingSort(arr,10,7);
 printf("\n\t after Sorting : ");
 for(int i=0;i<n;i++){
    cout<<" "<<arr[i];
 }
 return 0;
}

