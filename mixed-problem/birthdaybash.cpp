#include<bits/stdc++.h>
#define fast std::ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define test cout<<"archit\n"
#define debug(x) cout<<x<<" "
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define pb push_back
#define pi pair<int,int>
#define fi first
#define si second
#define mod (ll)1000000007
using namespace std;
ll ans=0;
ll dfs(vector< pair<int, int> >g[], int parent, int vertx)
{
    ll curr=1;
    for(auto i=g[vertx].begin();i!=g[vertx].end();i++){
        int neig = i->fi;
        if(neig!=parent){
            ll childvalue = dfs(g, vertx, neig);
//            debug1(childvalue);
//            debug2(curr, ans);
            ans+=((childvalue)%mod*i->si%mod*curr%mod)%mod;
            if(ans>=mod)
                ans%=mod;
            curr+=((childvalue)%mod*i->si%mod)%mod;
            if(curr>=mod)
                curr%=mod;
            //debug2(curr, ans);
        }
    }
    return curr;
}
int main()
{
    fast;
    int n,x,y,wt;
    cin>>n;
    vector< pair<int, int> >g[n+1];
    for(int i=1;i<n;i++){
        cin>>x>>y>>wt;
        g[x].pb(make_pair(y, wt));
        g[y].pb(make_pair(x, wt));
    }
//    for(auto i=g[1].begin();i!=g[1].end();i++){
//        debug2(i->fi, i->si);
//    }
    dfs(g, -1, 1);
    debug(ans);
    return 0;
}
