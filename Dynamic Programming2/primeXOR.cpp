#include <cstdio>
#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
const int maxn = 100002;
const int maxd = 4502;
const int mo = 1e9+7;
const int max_xor = (1<<13)-1;
int n,count[maxd];
bool is_prime[max_xor+2];
long long f[2][max_xor+2];
void init()
{
	for(int i=2;i<=max_xor;i++) is_prime[i]=true;
	for(int i=2;i<=max_xor;i++)
		if(is_prime[i])
		{
			int j=i<<1;
			while(j<=max_xor)
			{
				is_prime[j]=false;
				j+=i;
			}
		}
}
int main()
{
	init();
	int T;
	scanf("%d",&T);
while(T)
{
	T--;
	memset(count,0,sizeof(count));
	memset(f,0,sizeof(f));
	scanf("%d",&n);
	int tmp;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&tmp);
		count[tmp]++;
	}
	f[0][0]=1;
	int flag=1;
	for(int i=3500;i<=4500;i++)
	{
		for(int j=0;j<=max_xor;j++)
			if(count[i]==0)
				f[flag][j]=f[1-flag][j];
			else
				f[flag][j] = (f[1-flag][j]*(count[i]/2 + 1) % mo + f[1-flag][j^i]*((count[i]+1)/2) % mo) % mo;
		flag=1-flag;
	}
	long long ans=0;
	for(int j=0;j<=max_xor;j++)
		if(is_prime[j])
			ans = (ans + f[1-flag][j])%mo;
	printf("%lld\n",ans);
}
    return 0;
}
