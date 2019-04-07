#include <bits/stdc++.h>

#define mod 1000000007
#define inf 1000000000000
#define root2 1.41421
#define root3 1.73205
#define pi 3.14159
#define MAX 10001
#define ll long long int
#define PII pair<int, int>
#define f first
#define s second
#define ss(n) scanf("%d", &n)
#define mk make_pair
#define PLL pair<ll, ll>
#define pb push_back

using namespace std;

vector<PII> adj[MAX];
int par[MAX], n;
int depth[MAX];
int mcost[MAX];
int dp[MAX][15];//dp[i][j] denotes 2^j th ancestor of i

void dfs(int s, int pa)
{
    int i, x, w;
    for(i=0;i<adj[s].size();i++)
    {
        PII p=adj[s][i];
        x=p.f;
        if(x==pa)continue;
        w=p.s;
        par[x]=s;
        depth[x]=depth[s]+1;
        mcost[x]=mcost[s]+w;
        dfs(x, s);
    }
}
void initialize()
{
    int i, j;
    for(i=0;i<n;i++)
    {
        par[i]=i;
        depth[i]=0;
        mcost[i]=0;
    }
}
void precompute()
{
    dfs(0, -1);
    int i, j;
    //2^0 th ancestor is node's parent
    for(i=0;i<n;i++)
        dp[i][0]=par[i];
    for(j=1;(1<<j)<n;j++)
    for(i=0;i<n;i++)
    {
        //Compute i th node's 2^j th ancestor using bottom-up dp
        dp[i][j]=dp[dp[i][j-1]][j-1];
    }
}
int lca(int x, int y)
{
    //Assuming x is at deeper depth than y
    //If not swap those nodes
    int i;
    if(depth[x]<depth[y])
    {
        int temp=x;
        x=y;
        y=temp;
    }
    int diff=depth[x]-depth[y];
    //First find the level in which both nodes reside
    //move x upwards or in other words find ancestor of x having same level as y
    for(i=0;(1<<i)<n;i++)
    {
        if((diff>>i)&1)//i th bit of diff is set...move closer to y's level
            x=dp[x][i];
    }
    if(x==y)
        return x;
    //Now both have same level so move both upwards simultaneously
    for(i=14;i>=0;i--)
    {
        if(dp[x][i]!=x&&dp[x][i]!=dp[y][i])
        {
            x=dp[x][i];
            y=dp[y][i];
        }
    }
    //Now both x and y have same parents
    return par[x];
}
int main()
{
    int t, q, i, m, x, y, k, z, w;//m edges equal to n-1
    string ch;
    ss(t);
    while(t--)
    {
        ss(n);
        m=n-1;
        for(i=0;i<m;i++)
        {
            ss(x);
            ss(y);
            x--;y--;
            ss(w);
            adj[x].pb(mk(y, w));
            adj[y].pb(mk(x, w));
        }
        initialize();
        precompute();
        cin>>q;
        while(q--)
        {
            cin>>ch;
            if(ch[0]=='D')
            {
                ss(x);ss(y);
                x--;y--;
                printf("%d\n", mcost[x]+mcost[y]-2*mcost[lca(x, y)]);
            }
            else
            {
                ss(x);ss(y);ss(k);
                x--;y--;
                z=lca(x, y);
                if(depth[x]-depth[z]+1>=k)
                {
                    k--;
                    for(i=0;(1<<i)<n;i++)
                    {
                        if((k>>i)&1)
                            x=dp[x][i];
                    }
                    printf("%d\n", x+1);
                }
                else
                {
                    k=depth[x]+depth[y]-2*depth[z]+1-k;
                    for(i=0;(1<<i)<n;i++)
                    {
                        if((k>>i)&1)
                            y=dp[y][i];
                    }
                    printf("%d\n", y+1);
                }
            }
        }
        //Clear vectors
        for(i=0;i<n;i++)
            adj[i].clear();
        //Blank line
        printf("\n");
    }

}
