#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

int main(){
	// Write your code here
  int t;
  int arr[1234567];
  memset(arr, 0, sizeof(arr));
  for(int i=2;i<=100;i++){
     int c = i * i * i;
     for (int j=c;j<1234567;j=j+c) {

                    arr[j] = -1;

				}
  }
  int count=1;
  for(int i=1;i<1234567;i++){
    if(arr[i]!=-1){
      arr[i] = count;
      count++;
    }
  }
  cin>>t;
  int i=0;
  while(i!=t){
	int n;
    cin>>n;
      if(arr[n]==-1){
        printf("Case %d: Not Cube Free\n",i+1);
      }
      else{
        printf("Case %d: %d\n",i+1,arr[n]);
      }
    i++;
  }
	return 0;
}
