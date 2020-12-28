#include<stdio.h>
#include<conio.h>
void linear_search(int arr[], int n, int data){
    for(int i=0;i<n;i++){
        printf("\n\t harish irratation count  ");
        if(arr[i]==data){
         printf("\n\t data is found ");
         return ;
        }
    }
    printf("\n\t data is not found");
}
int main(){
    int arr[]={19,20,36,43,54,68,78,84,94,106};
    linear_search(arr,sizeof(arr)/sizeof(arr[0]),106);
getch();
return 0;
}
