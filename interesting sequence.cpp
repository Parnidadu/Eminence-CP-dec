#include<bits/stdc++.h>
using namespace std;
int main(){
int n , l , k;
cin>>n>>l>>k;
int a[n] , min1 , max1 , ans = 1e9;
cin>>a[0];
min1 =a[0] , max1 = a[0];
for(int j=1;j<n;j++){
cin>>a[j];
min1 = min(min1 , a[j]);
max1 = max(max1 , a[j]);
}
for(int j=min1;j<=max1;j++){
int inc =0 , dec=0;
for(int i=0;i<n;i++){
if(a[i]<j) inc+= j-a[i];
else dec += a[i]-j;
}
if(dec>inc) continue;
ans = min(ans,dec*l + (inc-dec)*k);
}
cout<<ans<<endl;
return 0;
}
