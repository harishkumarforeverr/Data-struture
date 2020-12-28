#include<stdio.h>
#include<conio.h>
void linear_search(int arr[], int n, int data){
   int l=0,u=n-1;
   while(l<=u) {
    printf("\n\t harish irratation count  ");
    int mid=(l+u)/2;
     if(arr[mid]==data){
        printf("\n\t data is found ");
        return ;
     }
     if(data>arr[mid])
        l=mid+1;
     else
        u=mid-1;
   }
   printf("\n\t data is not founf ");
}
int main(){
    int arr[]={19,20,36,43,54,68,78,84,94,106};
    linear_search(arr,sizeof(arr)/sizeof(arr[0]),106);
getch();
return 0;
}

