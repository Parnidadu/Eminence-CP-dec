#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

const int MAX = 1e5+1;
int mod = 1e9+7;

vector<int> divisors[MAX];
int A[MAX],S[MAX],F[MAX];

int mult(int a, int b)
{
	long long res = a;
  	res *= b;
  	return res % (mod);
}


int add(int a, int b)
{
	long long res = a;
  	res += b;
  	return res % (mod);
}


int power(int a, int b)
{
	int result = 1;
  	while(b)
    {
      	if(b&1)
        {
          	result = mult(result,a);
        }
      
      	a = mult(a,a);
      	b = b >> 1;
    }
  
  	return result;
}


void precompute()
{
	for(int i=2; i<=100000; i++)
    {
      	for(int j=i; j<=100000; j+=i)
        {
          	divisors[j].push_back(i);
        }
    }
}


int main()
{
  	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  
  	precompute();
	int t;
  	cin >> t;
  	while(t--)
    {
      	memset(F, 0, sizeof(F));
      	memset(S, 0, sizeof(S));
      	
 		int n,maxi = INT_MIN;
      	cin >> n;
      	for(int i=0; i<n; i++)
        {
          	cin >> A[i];
          	maxi = max(maxi,A[i]);
          	
          	for(int j=0; j<divisors[A[i]].size(); j++)
            {
              	F[divisors[A[i]][j]]++;
            }
        }
      
      	for(int i=maxi; i>=2; i--)
        {
          	mod = 1e9+6;
          	S[i] = (power(2,F[i]) - 1 + mod)%mod;
          	
          	for(int j=2*i; j<=maxi; j+=i)
            {
              	S[i] = (S[i] - S[j] + mod)%(mod);
            }
          
        }
      
      	int result = 1;
      	mod = 1e9+7;
      	for(int i=2; i<=maxi; i++)
        {
          	result = mult(result, power(i,S[i]));
        }
      
      	cout << result << endl;
      	
    }
}
