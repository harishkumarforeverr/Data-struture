#include<iostream>
using namespace std;
int sumf(int n){
 double sum=0;
  for(int i=1;i<=n;i++){
    sum=sum+i;
  }
  cout<<"\n\t sum : %d"<<sum;
}
void sumM(int n){
  double sum=(n*(n+1))/2;
  cout<<"\n\t sum : %d"<<sum;
}
int main(){
 printf("\n\t enter a no : ");
 int n;
 cin>>n;
 //sumf(n);
 sumM(n);
}
