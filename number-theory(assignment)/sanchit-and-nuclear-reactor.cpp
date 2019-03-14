#include<bits/stdc++.h>
using namespace std;
long long fact(int a, int m){
	long long res=1;
	for(int i=2;i<=a;i++)
		res=(res%m * i%m)%m;
	return res;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		long long t;
		int m;
		cin>>t>>m;
		if(t<m){
			if(m-t==1){
				cout<<1<<endl;
				continue;
			}
			else{
				cout<<fact(t, m)%m<<endl;
				continue;
			}
		}
		else{
			int last = t%m;
			long long facto=fact(last, m)%m;

			if((t/m)%2==0)
				cout<<facto<<endl;
			else
				cout<<((m-1)%m*facto%m)%m<<endl;
		}
	}
	return 0;
}
