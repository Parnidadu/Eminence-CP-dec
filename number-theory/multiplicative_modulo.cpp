class triplet{
  public:
    int gcd;
    int x;
    int y;
};
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
  
  
  //returning the multipliactive modulo inverse of A and B;
  return ans.x;
  
  
}

