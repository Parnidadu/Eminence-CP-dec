#include<bits/stdc++.h>
using namespace std;
vector<int> longestSubsequence(int *arr, int n){
	// Write your code here
  
  int storage,length;
  set<int> s;
  set<int>::iterator it;
  int ans=0;
  vector<int> v;
  for(int i=0;i<n;i++)
    s.insert(arr[i]);
  for(int i=0;i<n;i++){
    if(s.find(arr[i]-1)==s.end()){
      int j=arr[i];
      while(s.find(j)!=s.end())
        j++;
      if((j-arr[i])>ans){
        ans=(j-arr[i]);
        storage=arr[i];
        length=ans;
      }
      ans=max(ans,j-arr[i]);
    }
  }
  int k=0;
  for(it=s.begin();it!=s.end();it++){
    if(*it==storage){
      for(int z=0;z<length;z++){
        v.push_back(*it++);
      }
    }
  }
return v;
}  

/*this is just main function which is required on the assignment*/
