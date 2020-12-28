#include<stdio.h>
#include<conio.h>
void binarySearch(int arr[], int n, int item)
{
     int l=0;
     int u=n-1;
     while(l<=u)
     {
         int mid=(l+u)/2;
         if(arr[mid]==item)
         {
              printf("\n\t searching is sucessfully ");
              return ;
         }
         else if(item>arr[mid])
            l=mid+1;
         else
            u=mid-1;
     }
     printf("\n\t searching is unsucessfull");
}
int main()
{
    int arr[]={10,22,32,46,58,64,78,83,90,100};
    binarySearch(arr,10,32);
    getch();
    return 0;
}
