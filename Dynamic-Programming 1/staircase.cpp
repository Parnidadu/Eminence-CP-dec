#include<iostream>
using namespace std;

long staircase(int n){
    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    long *arr = new long[n+1];
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    for(int i=3;i<=n;i++){
        arr[i] = arr[i-1] + arr [i-2] + arr[i-3];
    }
    
    return arr[n];
}


int main(){

  int n; 
  cin >> n ;
  cout << staircase(n) << endl;

}


