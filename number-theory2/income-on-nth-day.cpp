#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

void multiply(long long A[2][2],long long M[2][2]){

	long long firstValue = ((A[0][0]%(mod-1) * M[0][0]%(mod-1))%(mod-1) + (A[0][1]%(mod-1) * M[1][0]%(mod-1))%(mod-1))%(mod-1);
	long long secondValue = ((A[0][0]%(mod-1) * M[0][1]%(mod-1))%(mod-1) + (A[0][1]%(mod-1) * M[1][1]%(mod-1))%(mod-1))%(mod-1);
	long long thirdValue = ((A[1][0]%(mod-1) * M[0][0]%(mod-1))%(mod-1) + (A[1][1]%(mod-1) * M[1][0]%(mod-1))%(mod-1))%(mod-1);
	long long fourthValue = ((A[1][0]%(mod-1) * M[0][1]%(mod-1))%(mod-1) + (A[1][1]%(mod-1) * M[1][1]%(mod-1))%(mod-1))%(mod-1);

	A[0][0] = firstValue;
	A[0][1] = secondValue;
	A[1][0] = thirdValue;
	A[1][1] = fourthValue;
	
}
void power(long long A[2][2],int n){
	if(n==1){
		return;
	}
	power(A,n/2);
	multiply(A,A);
	if(n%2 !=0){
		long long F[2][2] = {{1,1},{1,0}};
		multiply(A,F);
	}
}

long long getFibonacci(long long n){
	if(n==0 || n==1){
		return n;
	}
  long long A[2][2] = {{1,1},{1,0}};
  power(A,n-1);
  return A[0][0];
}


/*int calc(int n, int m, int k){
  if(n == 0){
    return m;
  }
  if(n == 1){
    return k;
  }
  return calc(n-1,m,k)+calc(n-2,m,k)+(calc(n-1,m,k)*calc(n-2,m,k))%mod;
}*/
long long modRec(long long a,long long b){
	if(b==0){
		return 1;
	}
	if(b%2==0){
		return modRec((a*a)%mod,b/2);
	}
	else{
		return ((a%mod)*modRec((a*a)%mod,(b-1)/2))%mod;
	}
}

int main() {

	// Write your code here
  int test;
  cin >> test;
  while(test--){
    long F0, F1, N;
    cin >> F0 >> F1 >> N;
    //cout << calc(N,F0,F1)%mod << endl;
    if(N==0){
      cout<<F0<<endl;
      continue; }
    if(N==1){ 
      cout<<F1<<endl; 
      continue; }
    long long a = F0 + 1;
    long long b = F1 + 1;
    long long x = getFibonacci(N-1)%(mod-1);
    long long y = getFibonacci(N)%(mod-1);
    long long result1 = modRec(a,x);
    long long result2 = modRec(b,y);
    long long calc = (result1%mod)*(result2%mod);
    calc = calc%mod;
    cout << calc -1<<endl;
  }
}
