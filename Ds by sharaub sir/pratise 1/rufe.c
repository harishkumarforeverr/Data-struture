#include<stdio.h>
#include<conio.h>
void quickAlogoritham(int[],int);
void quickSort(int arr[],int n, int beg, int end, int *loc)
{
    int left,right;
    left=beg;
    right=end;
                                printf("\n\t im here ");

step3 : while(arr[*loc]<arr[right]&&(*loc)!=right)
        right--;

    if((*loc)==right)
    {
        return ;
    }

    if(arr[*loc]>arr[right])
    {
        int temp=arr[right];
        arr[right]=arr[*loc];
        arr[*loc]=temp;
        *loc=right;
    }

    goto step2;
step2 :    while(arr[*loc]>arr[left]&&(*loc)!=left)
        left--;

    if(arr[*loc]==left)
    {
        return ;
    }
    if(arr[*loc]<arr[left])
    {
        int temp=arr[left];
        arr[left]=arr[*loc];
        arr[*loc]=temp;
        (*loc)=left;
    }
    goto step3;
}
int main()
{
    int arr[]={9,0,6,3,4,8,8,4,4,6};
    int n=(sizeof(arr)/sizeof(arr[0]));
    printf("\n\t size of array is : %d",n);
    printf("\n\t array elements before sorting : ");
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
  quickAlogoritham(arr,n);
    printf("\n\t array elements after sorting : ");
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
    getch();
    return 0;
}
void quickAlogoritham(int arr[],int n){
   int beg,end,stack1[10],stack2[10],index,*loc;
   beg=0;
   end=n-1;
   if(n<2)
   {
      printf("\n\t array is containg only one elmenets and is alerday sorted "); // do experimnents on these line
      return ;
   }
   index=0;
   stack1[index]=beg;
   stack2[index]=n-1;
   while(index!=-1)
   {

          beg= stack1[index];
          end= stack2[index];
          index--;
         /quickSort(arr,n,beg,end,*loc);
          if(beg<(*loc-1))
          {
              index++;
              stack1[index]=beg;
              stack2[index]=(*loc-1);
          }
          if((*loc+1)<end)
          {
              index++;
              stack1[index]=(*loc+1);
              stack2[index]=end;
          }
   }

}

