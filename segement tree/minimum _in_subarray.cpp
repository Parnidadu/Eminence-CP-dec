#include<bits/stdc++.h>
using namespace std;
 
void buildtree(int *a,int *tree,int si,int ei,int node) {
  if(si==ei) {
    tree[node]=a[si];
    return;
  }
  int mid=(si+ei)/2;
  buildtree(a,tree,si,mid,2*node);
  buildtree(a,tree,mid+1,ei,2*node+1);
  tree[node]=min(tree[2*node],tree[2*node+1]);
  return;
}
 
void update(int *a,int *tree,int si,int ei,int node,int idx,int value) {
  
    //here the condition is valid because we are at the specific point where we want to make
    //change and thats why we are writing si == ei, smjhe ki nii ;)
    if(si==ei) {
    a[idx]=value;
    tree[node]=value;
    return;
  }
  int mid=(si+ei)/2;
  if(idx>mid)
    update(a,tree,mid+1,ei,2*node+1,idx,value);
   else
     update(a,tree,si,mid,2*node,idx,value);
  tree[node]=min(tree[2*node],tree[2*node+1]);
    //do we need to write the return here, i don't think so. let's just comment it out
  // return;
}
 
int query(int *tree,int si,int ei,int node,int left,int right) {
  if(si>right || ei<left)
    return INT_MAX;
  if(si>=left && ei<=right)
    return tree[node];
  int mid=(si+ei)/2;
  int ans1=query(tree,si,mid,2*node,left,right);
  int ans2=query(tree,mid+1,ei,2*node+1,left,right);
 
  return min(ans1,ans2);
}
 
int main() {
 
	int n,q;
  cin>>n>>q;
  int *a=new int[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  int *tree=new int[4*n];
  buildtree(a,tree,0,n-1,1);
 
  while(q--){
    char w;
    int x,y;
    cin>>w>>x>>y;
    if(w=='q')
      cout<<query(tree,0,n-1,1,x-1,y-1)<<endl;
    else
      update(a,tree,0,n-1,1,x-1,y);
  }
  return 0;
}
