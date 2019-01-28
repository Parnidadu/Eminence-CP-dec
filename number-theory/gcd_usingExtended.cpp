class triplet{
  public:
    int gcd;
    int x;
    int y;
};
#include<iostream>
using namespace std;
triplet gcdExtended(int a,int b){
  	if(b==0){
      triplet myans;
      myans.gcd=a;
      myans.x=1;
      myans.y=0;
      return myans;
    }
     triplet smallans = gcdExtended(b,a%b);
 	 triplet myans;
     myans.gcd = smallans.gcd;
  //cout<<myans.gcd<<endl;
     myans.x = smallans.y;
     myans.y = smallans.x - ((a/b)*smallans.y);
    return myans;
}
int gcd(int a,int b)
{
	//Write your code here
  triplet ans = gcdExtended(a,b);
  
  
  //cout<<ans.x<<" "<<ans.y;
  return ans.gcd;
  
  
}

int main()
{
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b);
	return 0;
}
