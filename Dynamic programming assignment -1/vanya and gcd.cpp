

    #include <bits/stdc++.h>
    #define endl '\n';
    using namespace std;
     
    typedef long long int LL;
     
    const int mod=1e9+7;
     
    int a[505];
     
    LL dp[101][101][501];
    int gcd[101][101];
     
     
    void pre()
    {
    	for(int i=0;i<101;i++)
    	{
    		for(int j=1;j<101;j++)
    		{
    			gcd[i][j]=__gcd(i,j);
    		}
    	}
    }
     
    LL cool(int id,int g,int last,int n)
    {
    	if(id==n)
           return (g==1);
       if(dp[g][last][id]!=-1)
       	return dp[g][last][id];
      LL res=0;
      if(a[id]>last)
      res=cool(id+1,gcd[g][a[id]],a[id],n);
      res=(res+cool(id+1,g,last,n))%mod;
      dp[g][last][id]=res;
      return res;
    }
     
    int main()
    {
      ios_base::sync_with_stdio(false);cin.tie(0);
     
      //freopen("input.in","r",stdin);
     
              int n;
              cin>>n;
              
              pre();
      
              for(int i=0;i<101;i++)
              	for(int j=0;j<101;j++)
              	 for(int f=0;f<501;f++)
              	 	dp[i][j][f]=-1;
     
              for(int i=0;i<n;i++)
              	cin>>a[i];
               cout<<cool(0,0,0,n)<<endl;
     
      return 0;
    }
