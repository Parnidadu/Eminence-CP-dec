

    #include<bits/stdc++.h>
    using namespace std;
    int n,ar[105];
    int nxt[105][100005];
    vector<int> av;
    int mx;
    int S[105];
    int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    	cin>>ar[i];
    for (int s=0;s<=100000;s++)
    	nxt[n+1][s]=n+1;
    for (int i=1;i<=n;i++)
    	S[i]=S[i-1]+ar[i];
    for (int s=1;s<=100000;++s)
    {
    	int ptr=n;
    	for (int i=n;i;--i)
    	{
    	nxt[i][s]=nxt[i+1][s];
    	while (S[ptr]-S[i-1]>s)
    		--ptr;
    	if (S[ptr]-S[i-1]==s)
    		nxt[i][s]=ptr;
    	}
    }
    for (int sum=1;sum<=100000;sum++)
    {
    	int cur=1;
    	int cnt=0;
    	while (cur<=n)
    	{
    		if (nxt[cur][sum]!=n+1)
    			++cnt;
    		cur=nxt[cur][sum]+1;
    	}
    	if (cnt>mx)
    	{
    		av.clear();
    		mx=cnt;
    	}
    	if (cnt==mx)
    		av.push_back(sum);
    }
    cout<<mx<<endl;
    for (int i=0;i<av.size();i++)
    {
    	if (i)
    		cout<<" ";
    	cout<<av[i];
    }
    cout<<endl;
    //cin.get();cin.get();
    return 0;}

