#include<stdio.h>
#include<conio.h>
void quickSort(int arr[],int n,int beg,int end,int *loc){
    int left,right;
    left=beg;
    right=end;
    *loc=beg;
    step2:
        while(arr[*loc]<arr[right]&&*loc!=right)
            right--;
        if(*loc==right)
            return ;
        if(arr[*loc]>arr[right]){
            int temp=arr[*loc];
            arr[*loc]=arr[right];
            arr[right]=temp;
            *loc=right;
        }
        goto step3;
    step3 :
        while(arr[left]<arr[*loc]&&*loc!=left)
            left++;
        if(*loc==left)
            return ;
        if(arr[*loc]<arr[left]){
            int temp=arr[*loc];
            arr[*loc]=arr[left];
            arr[left]=temp;
            *loc=left;
        }
        goto step3;


}

void quickalgoritham(int arr[],int n){
   int beg,end,top=-1,loc;
   int lower[10],upper[10];
   beg=0;
   end=n-1;
   if(n>1){
    top++;
    lower[top]=beg;
    upper[top]=end;
   }
   while(top!=-1)
   {
       beg=lower[top];
       end=upper[top];
       top--;
       quickSort(arr,n,beg,end,&loc);
       if(beg<loc-1){
        top++;
        lower[top]=beg;
        upper[top]=loc-1;
       }
       if(loc+1<end){
        top++;
        lower[top]=loc+1;
        upper[top]=end;
       }
   }

}
int main()
{
    int arr[]={9,0,6,3,4,8};
    int n=(sizeof(arr)/sizeof(arr[0]));
    printf("\n\t array elenets before sorting :  ");
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
    quickalgoritham(arr,n);
    printf("\n\t array elenets after sorting :  ");
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);

}
