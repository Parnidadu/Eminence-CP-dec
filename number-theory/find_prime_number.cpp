#include<iostream>
#include <bits/stdc++.h> 
using namespace std;
int main(){
	// Write your code here
  int n,i=2;
  cin>>n;
  bool* arr= new bool[n+1];
  memset(arr,true,(n+1)*sizeof(bool));
  arr[0] = arr[1] = false;
  while(i<=n){
    if(arr[i] == true){
      int j = i*2;
      //j = j*2;
      while(j<=n){
        arr[j] = false;
        j = j+i;
      }
    }i++;
  }
  int count = 0;
  for(int i=0;i<=n;i++){
    if(arr[i] == true){
      count++;
    }
  }
  cout<<count;
	return 0;
}
