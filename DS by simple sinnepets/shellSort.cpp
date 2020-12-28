#include<iostream>
using namespace std;
void shellSort(int arr[],int n)
{
    cout<<endl;
    for(int gap=n/2; gap>0; gap=gap/2)
    {
        cout<<endl;
        for(int j=gap; j<n; j++)
        {
            int temp=arr[j];
            int i=0;
            for(i=j; (i>=gap)&&(arr[i-gap]>temp); i-=gap)
            {
                arr[i]=arr[i-gap];
            }
            arr[i]=temp;
        }
    }
}
int main()
{
    int arr[7]= {9,0,6,3,4,8,7};
    int n=7;
    printf("\n\t before sorting : ");
    for(int i=0; i<7; i++)
    {
        cout<<" "<<arr[i];
    }
    shellSort(arr,n);
    printf("\n\n\n\t after sorting : ");
    for(int i=0; i<7; i++)
    {
        cout<<" "<<arr[i];
    }
    cout<<"\n\n\n\t";

}
