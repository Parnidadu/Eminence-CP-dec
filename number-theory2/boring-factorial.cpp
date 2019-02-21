#include<bits/stdc++.h>
using namespace std;
long long pow_mod(long long a,long long b,long long m)
{
	long long x=1,y=a;
 	while(b>0){
      if(b & 1)
      x=(x*y)%m;
      y=(y*y)%m;
      b>>=1;
   	}
  return x;
}
int main() {

	// Write your code here
  int t;
  cin >> t;
  while(t--){
    long long p,n;
    cin >> n >> p;
    long long temp,result=-1;
		if(n>=p)
		{
			cout<<"0\n";
			continue;
		}
		for(int i=n+1;i<p;i++)
		{
			temp=pow_mod(i,p-2,p);
			result=(result*temp)%p;
		}
		cout<<result+p<<"\n";

  }
  return 0;
}
