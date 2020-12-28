#include<iostream>
using namespace std;
void linear_search(int arr[], int n){
   int index=-1;
   for(int i=0;i<6;i++)
    if(arr[i]==n)
   {
       index=i;
       break;
   }
   if(index==-1){
    printf("\n\t element NOT-Found ");
   }
   else {
    printf("\n\t element found at : %d",index);
   }
}
int main(){
 int arr[6]={9,0,6,3,4,8};
 printf("\n\t array values : ");
 for(int i=0;i<6;i++){
    printf(" %d ",arr[i]);
 }
  printf("\n\t enter the element to be earch  : ");
  int n;
  cin>>n;
  linear_search(arr,n);
  return 0;
}
