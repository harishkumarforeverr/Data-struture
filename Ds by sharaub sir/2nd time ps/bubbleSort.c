#include<stdio.h>
#include<conio.h>
void bubbleSort(int arr[], int n){
      for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){  // -1 anduku anthi array index starts from 0 and
            if(arr[j]>arr[j+1]){   // ekkada n-1-i i write -i becox in each irration oka value thana cooreect position lo poeee sittle aepothadi
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
      }
}
int main(){
    int arr[]={9,0,6,3,4,8};
    printf("\n\t array values before sorting : ");
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
        printf(" %d",arr[i]);
    bubbleSort(arr,sizeof(arr)/sizeof(arr[0]));
    printf("\n\t array values after sorting : ");
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    printf(" %d",arr[i]);
getch();
return 0;
}
