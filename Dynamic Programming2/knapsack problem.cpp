#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int knapsack(int* wt, int* val, int n, int W){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
  */
  int dp[W+1]; 
      
    //initially profit with 0 to W KnapSack capacity is 0 
    memset(dp, 0, sizeof(dp)); 
  
    // iterate through all items 
    for(int i=0; i < n; i++)  
        //traverse dp array from right to left 
        for(int j=W; j>=wt[i]; j--) 
            dp[j] = max(dp[j] , val[i] + dp[j-wt[i]]); 
    /*above line finds out maximum of  dp[j](excluding ith element value) 
      and val[i] + dp[j-wt[i]] (including ith element value and the 
      profit with "KnapSack capacity - ith element weight") */    
    return dp[W]; 
	// return ans;
}
int main(){

  int n; 
  cin >> n;
  int* weights = new int[n];
  int* values = new int[n];

  for(int i = 0; i < n; i++){
    cin >> weights[i];
  }

  for(int i = 0; i < n; i++){
    cin >> values[i];
  }

  int maxWeight;
  cin >> maxWeight;

  cout << knapsack(weights, values, n, maxWeight);

}
