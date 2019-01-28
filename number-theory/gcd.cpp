#include<iostream>
using namespace std;

int gcd(int a,int b)
{
	//Write your code here
  if(a==0){
    return b;
  }
  if(b==0){
    return a;
  }
  if(a>b){
    return gcd(a-b,b);
  }
  return gcd(a,b-a);
}
int main(){
  int a,b;
  cin>>a>>b;
  cout<<gcd(a,b);//calculating gcd of a and b
  return 0;
  }

