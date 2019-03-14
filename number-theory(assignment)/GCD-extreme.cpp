#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int phi(int n) 
{ 
    float result = n; // Initialize result as n 
  
    // Consider all prime factors of n and for every prime 
    // factor p, multiply result with (1 - 1/p) 
    for (int p = 2; p * p <= n; ++p) { 
          
        // Check if p is a prime factor. 
        if (n % p == 0) { 
              
            // If yes, then update n and result 
            while (n % p == 0) 
                n /= p; 
            result *= (1.0 - (1.0 / (float)p)); 
        } 
    } 
  
    // If n has a prime factor greater than sqrt(n) 
    // (There can be at-most one such prime factor) 
    if (n > 1) 
        result *= (1.0 - (1.0 / (float)n)); 
  
    return (int)result; 
} 

int main() {
	// your code goes here
    int n=1000000;
  ll *b=new ll[n+1];
  ll* result = new ll[n+1];
  for(ll i=0;i<=n;i++){
    b[i]=i;
     result[i]=0;
  }
  for(ll i=2;i<=n;i++) {
    if(b[i]==i) {
      for(ll j=i;j<=n;j+=i)
        b[j]=(b[j]*(i-1))/i;
    }
  }

  for(ll i=1;i<=n;i++) {
    for(ll j=2*i;j<=n;j+=i)
      result[j]=result[j]+b[j/i]*(i);
  }
 
  
  for(int i=1;i<=n;i++)
     result[i]=result[i]+result[i-1];
    while(1){
        int  k;
        cin >> k;
        if(k==0){
            break;
        }
        cout << result[k] <<endl;
    }
    
	return 0;
}
