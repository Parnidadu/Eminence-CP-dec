#include<stdio.h>  
#include<cstring>  
#define MAX(a,b) (a>b?a:b)  
int main()  
{  
    int n,m,k,l,r;  
    scanf("%d%d",&n,&m);  
    int a[n+5][m+5],maxn[n+5],tt[m+5];  
    memset(maxn,0,sizeof(maxn));  
    memset(tt,0,sizeof(tt));  
    for(int i = 0; i<n; i++)  
    for(int j = 0; j<m; j++)  
    {  
        scanf("%d",&a[i][j]);  
        if(i==0 || a[i][j]>=a[i-1][j]) tt[j]++;  
        else tt[j] = 1;  
        maxn[i] = MAX(maxn[i],tt[j]);  
    }  
    scanf("%d",&k);  
    for(int i = 0; i<k; i++)  
    {  
        scanf("%d%d",&l,&r);  
        if(r-l+1<=maxn[r-1]) puts("Yes");  
        else puts("No");  
    }  
    return 0;  
} 
