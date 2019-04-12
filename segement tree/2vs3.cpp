#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
#include<climits>
#include<stack>
using namespace std;
typedef long long int ll;
ll arr[100005]={0},tree[400005]={0};
struct in
{
    ll val,length;
};
typedef struct in in;
void cons(ll ss,ll se,ll si)
{
    if(ss>se)
        return;
    if(ss==se)
    {
        tree[si]=arr[ss];
        //cout<<"&&&"<<ss<<" "<<arr[ss]<<endl;
        return ;
    }
    ll mid=(ss+se)/2;
    cons(ss,mid,2*si+1);
    cons(mid+1,se,2*si+2);
    ll rLength=(se-(mid+1))+1;
    ll rVal=tree[2*si+2];
    ll lVal=tree[2*si+1];
    ll x=0;
    if(lVal==2)
    {
        //x=(1<<(rLength+1));
        if((rLength+1)%2==0)
            x=1;
        else
            x=2;
    }
    else if(lVal==1)
    {
        //x=(1<<rLength);
        if((rLength)%2==0)
            x=1;
        else
            x=2;
    }
    x+=rVal;
    x=x%3;
    /*ll mVal;
    if(rLength%2==0)
        mVal=1;
    else
        mVal=2;
    x=((lVal%3*mVal%3)%3+rVal%3)%3;
    */
    tree[si]=x;
    return;
}
in query(ll ss,ll se,ll s,ll e,ll si)
{
    if(ss>se || s>se || e<ss)
    {
        return ((in){0,0});                  //check
    }
    if(ss>=s && se<=e)
    {
        ll len=(se-ss)+1;
        return ((in){tree[si],len});
    }
    ll mid=(ss+se)/2;
    //ll rLength=(se-(mid+1))+1;
    ll rLength=0,lLength=0;
    in left=query(ss,mid,s,e,2*si+1);
    in right=query(mid+1,se,s,e,2*si+2);
    ll x=0;
    ll lVal=left.val;
    ll rVal=right.val;
    lLength=left.length;
    rLength=right.length;
    //rLength=(se-(mid+1))+1;
    //cout<<ss<<" "<<se<<" "<<lLength<<" "<<rLength<<" "<<lVal<<" "<<rVal<<endl;
    if(lVal==2)
    {
        //x=(1<<(rLength+1));
        if((rLength+1)%2==0)
            x=1;
        else
            x=2;
    }
    else if(lVal==1)
    {
        //x=(1<<rLength);
        if((rLength)%2==0)
            x=1;
        else
            x=2;
    }
    x+=rVal;
    x=x%3;
    /*ll mVal;
    if(rLength%2==0)
        mVal=1;
    else
        mVal=2;
    x=((lVal%3*mVal%3)%3+rVal%3)%3;
    */
    ll length=lLength+rLength;
    return ((in){x,length});
}
void update(ll ss,ll se,ll p,ll si)
{
    if(ss>se || p>se ||p<ss)
    {
        return ;
    }
    if(ss==p && se==p)
    {
        tree[si]=1;
        return;
    }
    ll dist=se-p;
    ll val=tree[si];
    if(dist%2==0)
        val+=1;
    else
        val+=2;
    val=val%3;
    tree[si]=(val);
    ll mid=(ss+se)/2;
    if(ss<=p&&mid>=p)
        update(ss,mid,p,2*si+1);
    else if(mid+1<=p&&se>=p)
        update(mid+1,se,p,2*si+2);
}
int main()
{
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    string s;
    ll tc,n,i,q,a,l,r,p;
  
        memset(tree,0,sizeof(tree));
        memset(arr,0,sizeof(arr));
        cin>>n;
        cin>>s;
        for(i=0;i<n;i++)
        {
            arr[i]=s[i]-'0';
            //cout<<arr[i]<<endl;
        }
        cons(0,n-1,0);
        cin>>q;
        while(q--)
        {
             cin>>a;
             if(a==0)
             {
                 cin>>l>>r;
                 cout<<query(0,n-1,l,r,0).val<<endl;
             }
             else
             {
                 cin>>p;
                 if(arr[p]==1)
                 {
                     //cout<<"nothing done"<<endl;
                 }
                 else
                 {
                    arr[p]=1;
                    update(0,n-1,p,0);
                 }
             }
        }
    //    fclose(stdout);
   // cout<<endl;
    return 0;
}
