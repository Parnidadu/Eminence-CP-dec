#include <bits/stdc++.h>

#define mod 1000000007
#define inf 1000000000000LL
#define root2 1.41421
#define root3 1.73205
#define pi 3.14159
#define MAX 10000001
#define cntbit __builtin_popcountll
#define ll long long int
#define PII pair<ll, ll>
#define f first
#define s second
#define mk make_pair
#define gc getchar
#define pb push_back

using namespace std;
ll fact[MAX], mbit=1000001, BIT[1000001];
bool cmp(pair<PII, PII> a, pair<PII, PII> b)
{
    return a.f.f>b.f.f;
}
bool cmp2(PII a, PII b)
{
    return a.f>b.f;
}
void update(int idx, ll val)
{
    while(idx<mbit)
    {
        BIT[idx]+=val;
        if(BIT[idx]>=mod)BIT[idx]-=mod;
        idx+=(idx&(-idx));
    }
}
ll query(int idx)
{
    ll sum=0;
    while(idx>0)
    {
        sum+=BIT[idx];
        if(sum>=mod)sum-=mod;
        idx-=(idx&(-idx));
    }
    return sum;
}
int main()
{
    int i, j, n, q, l, r, k;
    for(i=2;i<MAX;i++)
    {
        if(!fact[i])
        for(j=i;j<MAX;j+=i)
        fact[j]+=i;
    }
    cin>>n>>q;
    vector<ll> A(n+1), ans(q);
    vector<pair<PII, PII> > Q;
    vector<PII> v;
    for(i=1;i<=n;i++)
    {
        cin>>A[i];
        v.pb(mk(fact[A[i]], i));
    }
    sort(v.begin(), v.end(), cmp2);
    for(i=0;i<q;i++)
    {
        cin>>l>>r>>k;
        Q.pb(mk(mk(k, i),mk(l, r)));
    }
    sort(Q.begin(), Q.end(), cmp);
    int cnt=0;
    for(i=0;i<Q.size();i++)
    {
        k=Q[i].f.f;
        j=Q[i].f.s;
        l=Q[i].s.f;
        r=Q[i].s.s;
        while(cnt<n)
        {
            if(v[cnt].f<=k)break;
            update(v[cnt].s, (v[cnt].s * v[cnt].f)%mod);
            cnt++;
        }
        ans[j]=query(r)-query(l-1);
        if(ans[j]<0)ans[j]+=mod;
    }
    for(i=0;i<q;i++)
        cout<<ans[i]<<endl;
}
