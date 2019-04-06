#include<iostream>
#include<stdio.h>
#include<string.h>
#define mod 1000000007
using namespace std;
int memoiz[99][100][2];
int solve(int n, int k, int last)
{
    if(k < 0) return 0;
    if( n < 0 )return (k == 0);

    int &temp = memoiz[n][k][last];
    if( temp == -1 )
        temp = solve(n-1, k, 0) + solve(n-1, (last == 1 ) ? k - 1 : k, 1);
    return temp%mod;

}
int main()
{
    int t;
    scanf("%d", &t);
    memset(memoiz, -1, sizeof(memoiz));
    while(t-->0)
    {
        int numb, n, k;
        cin >> numb >> n >> k;
        // cases for first bit 1 or 0
        int result = solve(n-2, k, 0) + solve(n-2, k, 1);
        cout <<  numb<< " " << result%mod<< endl;
    }
    return 0;
}
