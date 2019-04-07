#include <bits/stdc++.h>

#define mod 5000000
#define inf 1000000000000
#define root2 1.41421
#define root3 1.73205
#define pi 3.14159
#define MAX 10005
#define ll long long int
#define PII pair<int, int>
#define f first
#define s second
#define ss(n) scanf("%d", &n)
#define ssf(n) scanf("%lf", &n)
#define mk make_pair
#define PLL pair<ll, ll>
#define gc getchar
#define pb push_back

using namespace std;
int BIT[MAX][52], n, A[MAX], S[MAX], dp[MAX][52], T[MAX], z;
int b_search(int x)
{
    int lo=1, hi=z, mid;
    while(lo<=hi)
    {
        mid=(lo+hi)>>1;
        if(S[mid]==x)
            return mid;
        if(S[mid]<x)
            lo=mid+1;
        else hi=mid-1;
    }
    return mid;
}
void update(int i, int j, int val)
{
    while(i<=n)
    {
        BIT[i][j]+=val;
        if(BIT[i][j]>=mod)
        BIT[i][j]-=mod;
        i+=(i&-i);
    }
}
int query(int i, int j)
{
    int sum=0;
    while(i)
    {
        sum+=BIT[i][j];
        if(sum>=mod)
            sum-=mod;
        i-=(i&-i);
    }
    return sum;
}
int main()
{
    int i, j, k;
    ss(n);
    ss(k);
    for(i=1;i<=n;i++)
    {
        ss(A[i]);
        T[i]=A[i];
    }
    sort(T+1, T+n+1);
    z=2;
    S[1]=T[1];
    for(i=2;i<=n;i++)
    {
        if(T[i-1]!=T[i])
            S[z++]=T[i];
    }
    for(i=1;i<=n;i++)
        A[i]=b_search(A[i]);
    memset(dp, 0, sizeof dp);
    memset(BIT, 0, sizeof BIT);
    int sum=0;

    for(i=1;i<=n;i++)
    {
        dp[i][1]=1;
        for(j=1;j<=min(i, k); j++)
        {
            dp[i][j]+=query(A[i]-1,j-1);
            //printf("%d %d %d\n", A[i], j, dp[i][j]);
            if(dp[i][j]>=mod)
                dp[i][j]-=mod;
            update(A[i], j, dp[i][j]);
        }
        sum+=dp[i][k];
        if(sum>=mod)
            sum-=mod;
    }
    printf("%d", sum);
}
