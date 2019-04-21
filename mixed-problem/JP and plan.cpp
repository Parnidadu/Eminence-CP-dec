#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
const ll mod=1e9+7;
int k;
int n,m;
int arr[500][500];
vector<pii> v;
int x[]={-1,0,1,0};
int y[]={0,-1,0,1};
bool visited[500][500];
int flag=0;
void sol(int x1,int y1)
{ // cout<<x1<<" "<<y1<<endl;
visited[x1][y1]=1;
v.push_back(pii(x1,y1));
for(int i=0;i<4;i++)
{
int nx=x1+x[i];
int ny=y1+y[i];
//cout<<nx<<" "<<ny<<endl;
if(nx>=0&&nx<n&&ny>=0&&ny<m&&(arr[nx][ny]==arr[x1][y1]||(arr[x1][y1]>arr[nx]
[ny]&&arr[x1][y1]-arr[nx][ny]<=k)))
{ // cout<<nx<<" "<<ny<<endl;
//cout<<arr[nx][ny]<<" "<<arr[x1][y1]<<endl;
if(visited[nx][ny])
continue;
if(nx==0||nx==n-1||ny==0||ny==m-1)
{
v.push_back(pii(nx,ny));
flag=1;
break;
}
sol(nx,ny);
if(flag==1)
return ;
}
}
if(flag==1)
return;
v.pop_back();
}
int main()
{
//int n,m;
cin>>n>>m;
//int arr[n][m];
int i,j;
for(int i=0;i<n;i++)
{
for(int j=0;j<m;j++)
{
cin>>arr[i][j];
}
}
int x,y;
cin>>x>>y>>k;
sol(x-1,y-1);
if(flag==1){
	cout<<"YES\n";
cout<<v.size()<<endl;
for(int i=0;i<v.size();i++)
cout<<v[i].first+1<<" "<<v[i].second+1<<endl;
}
else
cout<<"NO\n";
return 0;
}
