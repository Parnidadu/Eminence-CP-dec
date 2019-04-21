

    #include<bits/stdc++.h>
    const int N = 1050;
    using namespace std;
    int n, m;
    int dist[N];
    vector<int> g[N];
    void update(int v)
    {
    	for (int i = 0; i < g[v].size(); i++)
    	{
    		int to = g[v][i];
    		if (dist[to]>dist[v] + 1)
    		{
    			dist[to] = dist[v] + 1;
    			update(to);
    		}
    	}
    }
    int main(){
    	ios_base::sync_with_stdio(0);
    	cin >> n >> m;
    	for (int i = 2; i <= n; i++)
    		dist[i] = 1e9;
    	for (int i = 1; i <= m; i++)
    	{
    		int tp;
    		cin >> tp;
    		if (tp == 1)
    		{
    			int x;
    			cin >> x;
    			if (dist[x] > 1e8)
    				cout << -1 << endl;
    			else
    				cout << dist[x] << endl;
    		}
    		if (tp == 2)
    		{
    			int a, b;
    			cin >> a >> b;
    			g[a].push_back(b);
    			if (dist[b] > dist[a] + 1)
    			{
    				dist[b] = dist[a] + 1;
    				update(b);
    			}
    		}
    	}
    	return 0;
    }

