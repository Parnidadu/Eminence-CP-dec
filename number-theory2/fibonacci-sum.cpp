#define mod 1000000007

void multiply(long long A[2][2],long long M[2][2]){

	long long firstValue = ((A[0][0]%mod * M[0][0]%mod)%mod + (A[0][1]%mod * M[1][0]%mod)%mod)%mod;
	long long secondValue = ((A[0][0]%mod * M[0][1]%mod)%mod + (A[0][1]%mod * M[1][1]%mod)%mod)%mod;
	long long thirdValue = ((A[1][0]%mod * M[0][0]%mod)%mod + (A[1][1]%mod * M[1][0]%mod)%mod)%mod;
	long long fourthValue = ((A[1][0]%mod * M[0][1]%mod)%mod + (A[1][1]%mod * M[1][1]%mod)%mod)%mod;

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

long long fibo(long long n){
  if(n==0 || n==1){
		return n;
	}
  long long A[2][2] = {{1,1},{1,0}};
  power(A,n-1);
  return A[0][0];
}
long long fiboSum(long long m,long long n)
{
	// Write your code here
   long long msum,nsum;
   msum = fibo(m+1)%mod;
   nsum = fibo(n+2)%mod;
   //cout << msum << endl;
   //cout << nsum << endl;
   return (nsum-msum+mod)%mod;
}

