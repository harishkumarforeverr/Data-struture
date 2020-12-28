#include<stdio.h>
#include<conio.h>
void linearSearch(int arr[], int n , int item)
{
     int flag=0;
     for(int i=0;i<n;i++)
     {
          if(arr[i]==item)
          {
              flag=1;
              printf("\n\t search is sucessfully");
              return;
          }
     }
     if(!flag)
     printf("\n\t search is unsucessfull");
}
int main()
{
     int arr[]={9,0,6,3,4,8,8,4,4,6};
     linearSearch(arr,10,8);
     getch();
     return 0;
}
