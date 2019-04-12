#include<bits/stdc++.h>
#include <iostream>
using namespace std;
 
 
bool getPath(bool** edges,bool *visited,int s,int e,int n,vector<int>& path,int* ind)
{
    visited[s]=true;
    if(s==e)
    {
 
         path.push_back(s);
        return true;
    }
    for(int i=0;i<n;i++)
    {
        if(edges[s][i]&&!visited[i])
        {
 
            if(getPath(edges,visited,i,e,n,path,ind))
            {
 
                path.push_back(s);
                return true;
            }
        }
    }
    return false;
}
 
int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
 
 
       bool**edges=new bool*[V+2];
    bool *visited=new bool[V+2];
    for(int i=0;i<V;i++)
    {   visited[i]=false;
        edges[i]=new bool[V];
        for(int j=0;j<V;j++)
        {
            edges[i][j]=false;
        }
    }
    int s,d;
    for(int i=0;i<E;i++)
    {
        cin>>s>>d;
        edges[s][d]=true;
        edges[d][s]=true;
    }
    cin>>tempX>>tempY;
    vector<int> path;
 
   int ind=0;
 
    if(getPath(edges,visited,tempX,tempY,V,path,&ind))
    {
 
 
        for(int i=0;i<path.size();i++)
        {
            cout<<path[i]<<" ";
        }
    }
 
  return 0;
}
