#include<stdio.h>
#include<conio.h>
void quickSortAlgorithm(int arr[],int n,int beg,int end,int *loc){
   int left,right;
   left=beg;
   *loc=beg;
   right=end;
step2 : while(arr[*loc]<arr[right]&&*loc!=right)
        right--;
        if(*loc==right)
            return;
        if(arr[*loc]>arr[right]){
            int temp=arr[*loc];
            arr[*loc]=arr[right];
            arr[right]=temp;
            *loc=right;
        }
        goto step3;

step3 : while(arr[left]<arr[*loc]&&*loc!=left)
        left++;
        if(*loc==left)
            return ;
        if(arr[*loc]<arr[left]){
            int temp=arr[*loc];
            arr[*loc]=arr[left];
            arr[left]=temp;
            *loc=left;
        }
        goto step2;
}
void quickSort(int arr[],int n){
    int beg,end,loc,top=-1,lower_bound[10],upper_bound[10];
    beg=0;
    end=n-1;
    if(n>1){
        top++;
        lower_bound[top]=beg;
        upper_bound[top]=end;
    }
//    printf("\n\t %d %d %d %d %d",beg,end,lower_bound[top],upper_bound[top],top);
     while(top!=-1){
        beg=lower_bound[top];
        end=upper_bound[top];
        top--;
        quickSortAlgorithm(arr,n,beg,end,&loc);
        if(beg<loc-1){
            top++;
            lower_bound[top]=beg;
            upper_bound[top]=loc-1;
        }
        if(loc+1<end){
            top++;
            lower_bound[top]=loc+1;
            upper_bound[top]=end;
        }
     }
}
int main(){
    int arr[]={9,0,6,3,4,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("\n\t array values before sorting : ");
    for(int i=0;i<n;i++){
        printf(" %d",arr[i]);
    }
    quickSort(arr,n);
    printf("\n\t array values after sorting : ");
    for(int i=0;i<n;i++){
    printf(" %d",arr[i]);
    }
    getch();
    return 0;
}
