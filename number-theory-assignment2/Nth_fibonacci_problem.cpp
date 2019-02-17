#include<iostream>
using namespace std;
int fib(int n){
  if(n==1 || n==2){
    return 1;
  }
  return fib(n-1)+fib(n-2);
}

int main(){

       /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
  int n;
  cin >> n;
  cout << fib(n);
  return 0;
}


