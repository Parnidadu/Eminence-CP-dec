#include <bits/stdc++.h>

#define mod 1000000007
#define inf 2000000000
#define root2 1.41421
#define root3 1.73205
#define pi 3.14159
#define MAX 300001
#define ll long long int
#define PII pair<int, int>
#define f first
#define s second
#define ss(n) scanf("%lld", &n)
#define ssf(n) scanf("%lf", &n)
#define mk make_pair
#define PLL pair<ll, ll>
#define gc getchar
#define pb push_back
#define FR(i, a, b) for(ll i=(ll)a;i<=(ll)b;i++)
#define RFR(i, a, b) for(ll i=(ll)a;i>=(ll)b;i--)
using namespace std;
ll Table[MAX][20], A[MAX];

ll gcd(ll a, ll b)
{
    if(b==0)
        return a;
    else
        return gcd(b, a%b);
}
void preprocess(ll n)
{
    ll i, j;
    //initialize Table
    FR(i, 0, n-1)
        Table[i][0] = A[i];
    //compute values from smaller to bigger intervals
    for (j = 1; 1 << j <= n; j++)
        for (i = 0; i + (1 << j) - 1 < n; i++)
        {
            // j tells how much further to move from i
            if(Table[i][j - 1]>Table[i + (1 << (j - 1))][j - 1])
                Table[i][j] = gcd(Table[i][j - 1],Table[i + (1 << (j - 1))][j - 1]);
            else
                Table[i][j] = gcd(Table[i + (1 << (j - 1))][j - 1], Table[i][j - 1]);
        }
}
ll query(ll l, ll r, ll n)
{
    ll k=20;
    ll ans=0;
    ll i;
    RFR(i, k, 0)
    {
        if(l+(1<<i)-1<=r)
        {
            if(ans>Table[l][i])
                ans=gcd(ans, Table[l][i]);
            else
                ans=gcd(Table[l][i], ans);
            l+=1<<i;//increasing l
        }
    }
    return ans;

}
int main()
{
    ll n, q, l, r, i, ans;
    cin>>n;
    FR(i, 0, n-1)
        ss(A[i]);
    preprocess(n);
    ss(q);
    while(q--)
    {
        cin>>l>>r;
        l--;r--;
        ans=query(l, r, n);
        cout<<ans<<endl;
    }
}
