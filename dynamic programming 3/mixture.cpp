#include<bits/stdc++.h>
int totvol(vector<int> color,int i,int j){
    int sum=0;
    for(int k=i;k<=j;k++){
        sum+=color[k];
        sum=sum%100;
    }
    return sum;
}

// i is the starting point
//j is the ending point
int mix(vector<int>colors,int n,int** ans,int i,int j){
    //base case
    if(i==j){
        return 0;
    }
    if(ans[i][j]!=-1)
        return ans[i][j];
    
    int minsmoke=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int possibleans=mix(colors,n,ans,i,k)+mix(colors,n,ans,k+1,j)+ totvol(colors,i,k)* totvol(colors,k+1,j) ;
        if(possibleans<minsmoke){
            minsmoke=possibleans;
        }
    }
    ans[i][j]=minsmoke;
    return minsmoke;
    
}
int solve(int n,vector<int>colors)
{
	// Write your code here .
    int** ans=new int*[n];
    for(int i=0;i<n;i++){
        ans[i]=new int[n];
        for(int j=0;j<n;j++){
            ans[i][j]=-1;
        }
    }
return mix(colors,n,ans,0,n-1);
}
