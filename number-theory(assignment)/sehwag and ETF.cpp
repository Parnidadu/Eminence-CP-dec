#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
#define mk make_pair
ll power(ll a, ll b) {
ll x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>mod) x%=mod;
        }
        y = (y*y);
        if(y>mod) y%=mod;
        b /= 2;
    }
    return x;
}
ll prime[1000002];
vector<ll>x;
void sieve()
{
    ll i,j;
    for(i = 1LL; i <= 1000000LL; i++) {
        prime[i] = i;
    }
    for(i = 2LL; i <= 1000000LL; i++) {
        if(prime[i] == i) {
            for(j = 2; j*i <= 1000000LL; j++) {
                prime[j*i] = (i-1)*prime[j*i]/i;   
            }
            prime[i] = i-1;
            x.push_back(i);
        }
    }
}
ll arr[100005],brr[100005];
int main() 
{
	//freopen("Sample Input.in","r",stdin);
	//freopen("Sample Output.out","w",stdout);
    sieve();
   	int t;
   	cin>>t;
   	ll l = x.size();
   	while(t--) {
    	ll a,b,c,i,j,y,k;
    	cin>>a>>b>>k;
    	c = 0;
    	if(b <= 1000000) {
        	for(i = a; i <= b; i++) {
        		if(prime[i]%k == 0) {
        			c++;
        		}
        	}
    		printf("%.6lf\n",(double)(c)/(double)(b-a+1));
        	continue;
    	}
    	for(i = a; i <= b; i++) {
        	arr[i-a] = i;
        	brr[i-a] = i;
    	}
    	for(i = 0; i < l; i++) {
        	y = (a/x[i])*x[i];
        	for(j = y; j <= b; j += x[i]) {
            	if(j < a) {
                	continue;
            	}
            	while(brr[j-a]%x[i] == 0) {
                	brr[j-a] /= x[i];
            	}
            	arr[j-a] /= (x[i]);
            	arr[j-a] *= (x[i]-1);
        	}
    	}
    	for(i = a; i <= b; i++) {
        	if(arr[i-a] == i) {
            	arr[i-a] = i-1;
            	if(arr[i-a]%k == 0) {
            		c++;
            	}
            	continue;
        	}
        	else if(brr[i-a] != 1) {
            	arr[i-a] /= brr[i-a];
            	arr[i-a] *= (brr[i-a]-1);
        	}
        	if(arr[i-a]%k == 0) {
        		c++;
        	}
    	}
    	printf("%.6lf\n",(double)(c)/(double)(b-a+1));
   	}
	return 0;
}
