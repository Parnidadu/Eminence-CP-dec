#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<assert.h>
using namespace std;
#define Max_N 100001
typedef long long int ll;
long long int sum[Max_N];
int N,K,input[Max_N];
ll min(ll a,ll b)
{
    if(a>b)    return b;
    else return a;
}
int main()
{
    int val;
    scanf("%d%d",&N,&K);
    assert(1<=N && N<=100000);
    assert(1<=K && K<=N);
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&input[i]);
        assert(0<=input[i] && input[i]<=1000000000);
    }
    input[0]=0;
    sort(input+1,input+N+1);
    sum[0]=0;
    for(int i=1;i<=N;i++)    sum[i]=input[i]+sum[i-1];
    
    val=1-K;
    ll answer=0,compare,previous;
    for(int i=1;i<=K;i++){
        answer+=(ll)val*input[i];
        val+=2;
    }
    //printf("%lld is answeer\n",answer);
    previous=answer;
    for(int i=K+1;i<=N;i++){
        compare=(ll)(K-1)*input[i];
        compare=previous + (ll)(K-1)*input[i] + (ll)(K-1)*input[i-K]-(ll)2*(sum[i-1]-sum[i-K]);
        answer=min(answer,compare);
        previous=compare;
    }
    printf("%lld\n",answer);
    return 0;
}
