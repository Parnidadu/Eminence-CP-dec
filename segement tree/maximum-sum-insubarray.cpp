#include <iostream>
#include <climits>
#include <stdio.h>
using namespace std;
#define MAX 50002
int lv;
class Node{
public:
	int ss,max_left,max_right,total;
	Node(){
		// default constructor;
	}
	Node(int x){
		ss=max_left=max_right=total=x;
	}
};
class SegTree{
	int *a;
	Node *tree;
	int n;
public:
	SegTree(int n,int *a){
		this->a=a;
		this->n=n;
		tree=new Node[4*MAX];
		build_rec(0,0,n-1);
	}
	int query(int x,int y){
		return query_rec(0,0,n-1,x,y).ss;
	}
private:
	int maxf(int a,int b,int c,int d){
		return max(a,max(b,max(c,d)));
	}
	int maxf(int a,int b,int c){
		return max(a,max(b,c));
	}
	void build_rec(int node,int s_start,int s_end){
		if(s_start==s_end){
			tree[node].ss=tree[node].max_left=tree[node].max_right=tree[node].total=a[s_end];
			return;
		}
		int mid=(s_end+s_start)/2,left=2*node+1,right=left+1;
		build_rec(left,s_start,mid);
		build_rec(right,mid+1,s_end);
		tree[node].max_left=maxf(tree[left].max_left,tree[left].total,tree[left].total+tree[right].max_left);
		tree[node].max_right=maxf(tree[right].max_right,tree[right].total,tree[right].total+tree[left].max_right);
		tree[node].total=tree[left].total+tree[right].total;
		tree[node].ss=maxf(tree[left].ss,tree[right].ss,tree[left].max_right+tree[right].max_left);
	}
	Node query_rec(int node,int s_start,int s_end,int l,int h){
		if(s_start>h or s_end<l)return Node(lv);
		if(s_start==s_end)return tree[node];
		int left=2*node+1,right=left+1, mid=(s_end+s_start)/2;
		if(s_start>=l and s_end<=h)return tree[node];
		Node leftNode=query_rec(left,s_start,mid,l,h);
		Node rightNode=query_rec(right,mid+1,s_end,l,h);
		Node temp;
		temp.max_left=maxf(leftNode.max_left,leftNode.total,leftNode.total+rightNode.max_left);
		temp.max_right=maxf(rightNode.max_right,rightNode.total,rightNode.total+leftNode.max_right);
		temp.total=leftNode.total+rightNode.total;
		temp.ss=maxf(leftNode.ss,rightNode.ss,leftNode.max_right+rightNode.max_left);
		return temp;
	}
};
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	lv=INT_MAX;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		lv=min(lv,a[i]);
	}
	lv=min(lv,0);
	SegTree tree(n,a);
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		x--;
		y--;
		if(x==y)
			printf("%d\n", a[x]);
		else
			printf("%d\n", tree.query(x,y));
	}
}
