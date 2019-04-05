#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
 
long long num_codes(string s) {
  ll *output=new ll[s.size()+1];
  output[0]=1;
  output[1]=1;
  for(int i=2;i<=s.size();i++) {
    if(s[i-1]!='0') {
    output[i]=output[i-1];
    if(((s[i-2]-48)*10+(s[i-1]-48))>=10 && ((s[i-2]-48)*10+(s[i-1]-48))<=26)
      output[i]=(output[i]+output[i-2])%mod;
    }
    else {
      if(s[i-2]=='0' || s[i-2]>50)
        return 0;
        output[i]=output[i-2]%mod;
    }
  }
  ll ans=output[s.size()];
  delete []output;
  return ans;
}
 
int main() {
  while(true) {
     string s;
    cin>>s;
    if(s[0]=='0')
      break;
    cout<<num_codes(s)<<endl;
  }
    return 0;
}
