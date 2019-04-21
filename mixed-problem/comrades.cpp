

    #include<iostream>
    #include<vector>
    using namespace std;
    vector<int> adj[100001];
    int heightof[100001];
    int dfsin[100001],dfsout[100001];
    int dfsnumber;
    void dfs(int at,int height)
    {
        vector<int>::iterator it;
        heightof[at]=height;
        dfsin[at]=dfsnumber;
        dfsnumber++;
        it=adj[at].begin();
        while(it!=adj[at].end())
        {
            dfs((*it),height+1);
            it++;
        }
        dfsout[at]=dfsnumber;
        dfsnumber++;
        return;
    }
    int main()
    {
        int t;
        //cin>>t;
        scanf(" %d",&t);
        while(t--)
        {
            int n,i,root,par;
            //cin>>n;
            scanf(" %d",&n);
            i=1;
            while(i<=n)
            {
                adj[i].clear();
                dfsin[i]=0;
                dfsout[i]=0;
                i++;
            }
            i=1;
            while(i<=n)
            {
                //cin>>par;
                scanf(" %d",&par);
                if(par==0)
                {
                    root=i;
                }
                else
                {
                    adj[par].push_back(i);
                }
                i++;
            }
            dfsnumber=0;
            dfs(root,0);
          /*  i=1;
            while(i<=n)
            {
                cout<<i<<" "<<dfsin[i]<<" "<<dfsout[i]<<" "<<heightof[i]<<endl;
                i++;
            }
            cout<<endl;*/
            int q,x,y;
           // cin>>q;
           scanf(" %d",&q);
            while(q--)
            {
                //cin>>x>>y;
                scanf(" %d %d",&x,&y);
                if(dfsin[y]<dfsin[x] && dfsout[x]<dfsout[y])
                {
                   cout<<heightof[x]-heightof[y]-1<<endl;
                }
                else
                {
                    cout<<"-1"<<endl;
                }
            }
        }
        return 0;
    }

