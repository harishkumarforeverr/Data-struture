#include<iostream>
#include<stack>
using namespace std;
bool isOperand(char ch){
  if( (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') )
  return true;
  else 
  return false;
}
string pToI(string postfix){
	 stack<string> s;
	 for(int i=postfix.length()-1;i>=0;i--){
	 	 if(isOperand(postfix[i])){
	 	 	string op(1,postfix[i]);
	 	 	s.push(op);
		  }
		  else{
		  	string op1=s.top();
		  	s.pop();
		  	string op2=s.top();
		  	s.pop(); 
		  	s.push( op1+op2+postfix[i]);
		  }
	 }
	 return s.top();
}
int main(){
  string str="/*-+abc^d^efg";
  cout<<"\n\t output : "<<pToI(str);
}
