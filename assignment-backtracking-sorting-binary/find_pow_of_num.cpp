
#include<iostream>
using namespace std;
int pow(int x,int n){
  if(n==0){
    return 1;
  }
  return x*pow(x,n-1);
}
int main() {
	// Write your code here
	int x,n,result;
    cin>>x>>n;
    result= pow(x,n);
    cout<<result;
    return 0;
}
