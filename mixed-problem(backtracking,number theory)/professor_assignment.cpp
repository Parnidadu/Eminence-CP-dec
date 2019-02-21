#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main()
{
  
  long long int n;
  cin >> n;
 // int mod=1000000007;
  long i=1;
  long sum=0;
  long t=500000004;

  while(i<=n){
    long temp;
    long x=n/i;
    long j=n/x;
    long y=(((((x)%mod)*((x+1)%mod))%mod)*t)%mod;

    temp=(((((j-i+1)%mod)*((i+j)%mod))%mod)*t)%mod;

    sum=((sum+(temp*y)%mod))%mod;

    i=j+1;
  }

  cout << sum;
  return 0;
}
