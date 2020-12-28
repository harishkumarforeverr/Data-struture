#include<stdio.h>
#include<conio.h>
// bubblesort program
void bubbleSort(int [], int);
int main()
{
     int arr[]={9,0,6,3,4,8,8,4,4,6};
     int n=sizeof(arr)/sizeof(int);
     printf("\n\t array values before sorting :");
     for(int i=0;i<n;i++)
     printf(" %d ",arr[i]);
     bubbleSort(arr,n);
     printf("\n\t array values after sorting :");
     for(int i=0;i<n;i++)
     printf(" %d ",arr[i]);
}
void bubbleSort(int arr[], int n)
{
     for(int i=0;i<n;i++)
     {
          for(int j=0;j<n-1-i;j++) // i took n-1-i see papers in your notes i explained there
          {
              if(arr[j]>arr[j+1])
              {
                   int temp=arr[j];
                   arr[j]=arr[j+1];
                   arr[j+1]=temp;
              }
          }
     }
}
