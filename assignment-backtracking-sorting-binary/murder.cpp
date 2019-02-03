#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int arr[n],result[n],temp=0;
    result[0]=0;
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    for(int i=1;i<n;i++){
      int sum=0;
      for(int j=0;j<i;j++){
        if(arr[j]<arr[i]){
          sum=sum+arr[j];
        }
      }
      result[i]=sum;
    }
    for(int i=0;i<n;i++){
     temp=temp+result[i];
    }
    cout<<temp<<endl;
  }
}
