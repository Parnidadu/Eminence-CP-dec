#include <bits/stdc++.h>
using namespace std;
int dp[1000001] = {0};
int dp2[1000001] = {0};
int r_sum[1000001] = {0};
int main()
{
	int t,n;
	scanf(" %d",&t);
	scanf(" %d",&n);
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf(" %d %d",&x,&y);
		//We mark the ranges, this will help us fill up the dp
		dp[x] += 1;
		dp[y+1] -= 1;
	}
	//We fill up the dp
	//After this operation dp[i] will tell us how many coins are there in ith coin box
	for(int i=1;i<=t;i++)
	{
		dp[i] += dp[i-1];
		//printf(" %d",dp[i]);
	}
	//How many coin boxes has exactly i coins? dp2[i] is this value
	for(int i=0;i<1000001;i++)
	{
		dp2[dp[i]]++;
	}
	//Now we maintain a running sum of dp2 from left to right
	//So r_sum[i] will tell us for how many coin boxes has atleast i coins in them
	r_sum[1000000] = dp2[1000000];
	for(int i=999999;i>=0;i--)
	{
		r_sum[i] = dp2[i] + r_sum[i+1];
	}
	//Now for each query we return the answer in O(1)
	int q;
	scanf(" %d",&q);
	while(q--)
	{
		int z;
		scanf(" %d",&z);
		printf("%d\n",r_sum[z]);
	}
	return 0;
}
