// assuming user is not entering any zero  values becox i took cond in program that return 0 is cond is false and return 1 if cond is true ;
#include<iostream>
#include<conio.h>
using namespace std;
class A
{
    private : int capacity;
    int left;
    int right;
    int *ptr;
    public :
    A(int capacity)
    {
        this->capacity=capacity;
        left=-1;
        right=capacity;
        ptr=new int[capacity];
    }
    ~A()
    {
        delete []ptr;
    }
    void pushleft(int val)
    {
        if(isfull())
        {
            cout<<"\n\t overflow from left ";
            return ;
        }
        else
        {
            left++;
            ptr[left]=val;
        }
    }
    void pushright(int val)
    {
        if(isfull())
        {
            cout<<"\n\t overflow from right ";
            return ;
        }
        else
        {
            right--;
            ptr[right]=val;
        }
    }
    int popleft()
    {
        if(isemptyleft())
        {
            cout<<"\n\t underflow from left ";
            return 0;
        }
        else
        {
            // using user is not entered a zero values
            left--;
            return 1;
        }
    }
    int popright()
    {
        if(isemptyright())
            return 0;
        else
        {
            right++;
            return 1;
        }
    }
    void peekleft()
    {
        if(isemptyleft())
        cout<<"\n\t list is empty ";
        else
        {
            cout<<"\n\t values are = ";
            for (int i=0;i<=left;i++)
                cout<<" "<<ptr[i];
        }
    }
    void peekright()
    {
        if(isemptyright())
            cout<<"\n\t list is empty from right ";
        else
        {
                cout<<"\n\t values from right are = ";
                for(int i=capacity-1;i>=right;i--)
                cout<<" "<<ptr[i];
        }
    }
    int isemptyleft()
    {
        if(left==-1)
            return 1;
        else
            return 0;
    }
    int isemptyright()
    {
        if(right==capacity)
            return 1;
        else
            return 0;
    }
    int isfull()
    {
        if(left+1==right)
            return 1;
        else
            return 0;
    }
};
int main()
{
    A o(10);
    o.pushleft(8);
    o.pushleft(2);
    o.pushleft(4);
    o.pushleft(7);
    o.pushleft(3);
    o.peekleft();
    o.pushright(9);
    o.pushright(6);
    o.pushright(3);
    o.pushright(4);
    o.pushright(2);
    o.peekright();
    o.popleft();
    o.peekleft();
    o.popleft();
    o.peekleft();
    o.popright();
    o.peekright();
    o.popright();
    o.peekright();

}
