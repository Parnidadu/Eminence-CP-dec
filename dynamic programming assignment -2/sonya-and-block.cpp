#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli dp[105][1010];
lli  arr[1000100];
lli best[1001000];
#define inf -1000000000000
int main()
 {
     memset(dp,inf,sizeof dp);
     int n,m;
     dp[0][0]=0;
      cin>>n>>m;
      arr[0]=0;
     for(int i=1;i<=n;i++)
      {
         int t;
         cin>>t;
         for(int j=1;j<=t;j++)
           {
           scanf("%lld",&arr[j]);
            arr[j]=arr[j-1]+arr[j];
            best[j]=inf;
           }
 
    best[0]=0;
    
    for(int j=1;j<=m && j<=t;j++)//  chossing best of lendth j from the given array
     {
        for(int k=1;k<=t;k++)// fixing start point of best of length j 
         { 
            
              if(k+j-1<=t)
               {
                  best[j]=max(best[j],arr[k+j-1]-arr[k-1]);
      }
   
    }
     }
     
     // using all best of this array to contribute in the final array which will
     // contain at most m elelemts 
     for(int k=0;k<=m;k++) dp[i][k]=dp[i-1][k];// COPYING PRIVIOUS STATE IE ANS COMPUTED 
                                               //  TILL THE LAST ARRAY USED 
     for(int j=1;j<=m && j<=t;j++)  
      {
         for(int k=0;k<=m;k++)
          {
                 if(k+j<=m   && dp[i-1][k]!=-1)
                  {
                   dp[i][k+j]=max(dp[i][k+j],dp[i-1][k]+best[j]);
          }
       }
   }
   }
   long long int ans=0;
   for(int i=0;i<=m;i++)
    {
     ans=max(ans,dp[n][i]);
    }
    cout<<ans<<endl;
 }
