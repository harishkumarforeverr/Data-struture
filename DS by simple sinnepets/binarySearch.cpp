#include<iostream>
using namespace std;
void binarySearch(int arr[], int x, int l, int r)
{
   int index=-1;
   int mid=0;
   while(l<=r){
     mid=l+(r-l)/2;
     if(arr[mid]==x){
        index=mid;
        break;
     }
     else if(arr[mid]>x){
        r=mid-1;
     }
     else {
        l=mid+1;
     }
   }
   if(index==-1){
    printf("\n\t NOT found");
   }
   else{
    printf("\n\t founded %d ", index);
   }
}
int main(){
   int arr[6]={0,3,4,6,8,9};
   printf("\n\t array values : ");
   for(int i=0;i<6;i++){
    printf("\n\t %d ",arr[i]);
   }
   printf("\n\t enter the element you want to search : ");
   int n;
   cin>>n;
   binarySearch(arr, n, 0,5);
return 0;
}
