#include<bits/stdc++.h>
using namespace std;
//#define fast ios_base::sync_with_stdio(0);cin.tie(0);
struct node
{
int data,anc;
node *next;
};
node *q[2010];
int inter[2010];
void join(int a,int b)
{
node *newnode=new node;
newnode->data=b;
newnode->anc=-1;
newnode->next=NULL;
if(q[a]==NULL)
q[a]=newnode;
else
{
//node *temp=q[a];
newnode->next=q[a];
q[a]=newnode;
}
}
int dfs(node *a,int flag)
{
while(a!=NULL)
{
if(inter[a->data]==flag)
return 0;
inter[a->data]=1-flag;
a=a->next;
}
return 1;
}
int main()
{
int t,tc=1;
scanf("%d",&t);
while(tc<=t)
{
int e,v;
scanf("%d%d",&v,&e);
//int *q[v+10];
for(int i=0;i<v+10;i++)
q[i]=NULL;
memset(inter,-1,sizeof(inter));
for(int i=1;i<=e;i++)
{
int a,b;
scanf("%d%d",&a,&b);
join(a,b);
join(b,a);
}
int check=0;
int flag=1,flag1;
for(int i=1;i<=v;i++)
{
flag1=0;
if(q[i]!=NULL)
{
Coding Ninjas
if(inter[i]==-1)
{
inter[i]=flag;
}
else
flag=inter[i];
check=dfs(q[i],flag);
if(check==0)
{
flag1=1;
break;
}
}
}
printf("Scenario #%d:\n",tc);
if(flag1==1)
printf("Suspicious bugs found!\n");
else
{
printf("No suspicious bugs found!\n");
}
}
}
