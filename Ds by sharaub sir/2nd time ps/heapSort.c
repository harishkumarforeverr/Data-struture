#include<stdio.h>
#include<conio.h>
int main(){
    int c,root;
    int arr[]={6,5,3,1,8,7,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("\n\t stage-1 : ");
    for(int i=0;i<n;i++)
      printf(" %d ",arr[i]);

    for(int i=1;i<n;i++){
        c=i;
        do{
            root=(c-1)/2;
            if(arr[root]<arr[c]){
                int temp=arr[root];
                arr[root]=arr[c];
                arr[c]=temp;
            }
            c=root;
        }while(c!=0);
    }
    printf("\n\t stage-2 : ");
    for(int i=0;i<n;i++)
    printf(" %d ",arr[i]);

  for(int i=n-1;i>=0;i--){
    int temp=arr[0];
    arr[0]=arr[i];
    arr[i]=temp;
    root=0;
       do{
         c=2*root+1;
         if(arr[c]<arr[c+1]&&c<i-1)
            c++;
         if(arr[root]<arr[c]&&c<i){
            temp=arr[root];
            arr[root]=arr[c];
            arr[c]=temp;
         }
         root=c;
         }while(c<i-1);
  }
    printf("\n\t stage-3 : ");
    for(int i=0;i<n;i++)
    printf(" %d ",arr[i]);

getch();
return 0;
}











