#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1000000007


ll modRecursive(ll a, ll b){
	if(b == 0){
		return 1;
	}

	if(b%2 ==0){

		//Even
		return modRecursive((a*a)%MAX,b/2);
	}else{
		// Odd
		return ((a%MAX)*(modRecursive((a*a)%MAX,b/2)))%MAX;
	}

}




int main(){
	long long* fact_dp = new long long[1000001];
	fact_dp[0]=1;
	fact_dp[1]=1;
	for(ll i=2;i<1000001;i++){
		fact_dp[i] = (fact_dp[i-1]%MAX*i%MAX)%MAX;
	}
	long t;
	cin>>t;
	while(t--){
		long n,k;
		cin>>n>>k;
		ll a,b,c,d;
		a=fact_dp[n];
		b=fact_dp[k];
		c=fact_dp[n-k];
		b=modRecursive(b, MAX-2);
		c=modRecursive(c, MAX-2);
		d = modRecursive(2, k);
		ll res = (((a%MAX * b%MAX)%MAX * c%MAX)%MAX * d%MAX)%MAX;
		cout<<res<<endl;
	}
}
