#include<stdio.h>
#include<conio.h>
int main(){
  int arr[]={9,0,6,3,4};
  int n=sizeof(arr)/sizeof(arr[0]);
  int root,temp;
  printf("\n\t array elements at instal stage : ");
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
  for(int i=1;i<n;i++){ // i took i=1 becoz we want to compare the child elements with parent element
    int c=i;
     do{
        root=(c-1)/2; // formula to get the parent node
        if(arr[root]<arr[c]){
            temp=arr[c];
            arr[c]=arr[root];
            arr[root]=temp;
        }
        c=root;
     }while(c!=0);
  }
  printf("\n\t array elements after heapfy stage : ");
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }

   for(int i=n-1;i>=2;i--){
   temp=arr[0];
   arr[0]=arr[i];
   arr[i]=temp;
   root=0;
   int c;
   do{
        c=2*root+1; //// formula to get the child node
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

  printf("\n\t array elements after heapfy stage : ");
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
}




















