#include<iostream>
using namespace std;
int res=0;
int sqrt(int n, int max, int min)
{
    if(max==0){
        max=n;
    }
    res=(max+min)/2;
    if(res*res == n){
        return res;
    }
    else if(res*res > n){
        max =res;
    }
    else {
        min=res;
    }
        return sqrt(n,max,min);
}
int main(){
    cout<<" value :"<<sqrt(25,0,0);
}
