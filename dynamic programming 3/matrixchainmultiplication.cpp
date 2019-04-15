#include<bits/stdc++.h>
int mcm1(int* arr,int** ans,int i,int j){
    //base case
    if(i==j)
        return 0;
    // handling an overlapping subproblem
    if(ans[i][j]!=-1){
        return ans[i][j];
    }
    
    int mincost=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int possibleans=mcm1(arr,ans,i,k)+mcm1(arr,ans,k+1,j)+arr[i-1]*arr[k]*arr[j] ;//Induction step
        /*
         Notice above we are acessing dimension i-1 this is where our stating i from 1(and not zero) provides us acessibility
         */
        if(possibleans<mincost){//MINIMUM OF ALL K -is the answer
            mincost=possibleans;// Induction hypothesis
        }
    }
    ans[i][j]=mincost;
return mincost;
}
int mcm(int* p, int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
  */
    int** ans=new int*[n+1];
    for(int i=0;i<n+1;i++){
        ans[i]=new int[n];
        for(int j=0;j<n+1;j++){
            ans[i][j]=-1;
        }
    }
    return mcm1(p,ans,1,n);

}
