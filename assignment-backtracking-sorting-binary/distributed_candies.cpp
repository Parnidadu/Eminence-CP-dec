#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

bool check(int *arr,int n,int val,int k){
  int count = 0;
        for (int i = 0; i < n; i++) {
            int smallans = arr[i] / val;
            count += smallans;

            if (count >= k) {
                return true;
            }
        }
        return false;
        
}
int distcandies(int *arr,int n,int k){
  int max=arr[n-1];
  int min = 0;
  int ans = 0;
  while(min<=max){
     int mid = (min + max) / 2;
            if (check(arr,n,mid,k)) {
                ans = mid;
                min = mid + 1;
            } else {
                max = mid - 1;
            }

        }
	return ans;
}
int main(){
	// Write your code here
  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin >> n >> k;
    int* arr=new int[n];
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    sort(arr,arr+n);        
    int ans = distcandies(arr,n,k); 
    cout<<ans<<endl;
  } 
  return 0;
}
