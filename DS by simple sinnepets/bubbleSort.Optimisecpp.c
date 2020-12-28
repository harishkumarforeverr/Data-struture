#include<iostream>
using namespace std;
void optimizedbubbleSort(int arr[], int n)
{
    for(int i=0;i<n-1;i++){
        int flag=false;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                flag=true;
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        if(!flag)
        break;

    }
}
int main(){
  int arr[7]={9,0,6,3,4,8,7};
  printf("\n\t before Sorting : ");
  for(int i=0;i<7;i++)
    cout<<arr[i]<<" ";
  optimizedbubbleSort(arr, 7);
  printf("\n\t before Sorting : ");
  for(int i=0;i<7;i++)
    cout<<arr[i]<<" ";
return 0;
}
