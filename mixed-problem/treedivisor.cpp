#include<bits/stdc++.h>
using namespace std;
 
int calcStrength(vector<int>* edges, long long* noOfDivisors, int toInclude, int toExclude, int vertex)
{ 
  if(toInclude == 1)
  {
    int inclusive = noOfDivisors[vertex];
    int exclusive = 0;
 
    for(int i=0; i<edges[vertex].size(); i++)
    {
      inclusive += calcStrength(edges, noOfDivisors, 0, 1, edges[vertex][i]);
    }
 
    for(int i=0; i<edges[vertex].size(); i++)
    {
      exclusive += calcStrength(edges, noOfDivisors, 1, 0, edges[vertex][i]);
    }
 
    return max(inclusive, exclusive);
  }
 
  if(toExclude == 1)
  {
    int exclusive = 0;
 
    for(int i=0; i<edges[vertex].size(); i++)
    {
      exclusive += calcStrength(edges, noOfDivisors, 1, 0, edges[vertex][i]);
    }
 
    return exclusive;
  }
 
  //every case will be covered in either of the above case
}
 
int main()
{
  int N;
  cin >> N;
 
  bool* isPrime = new  bool[N+1];// bool[N/2+1];
 
  for(int i=0; i<N+1; i++)
  {
    isPrime[i] = true;
  }
 
  isPrime[0] = false;
  isPrime[1] = false;
 
  long long* noOfDivisors = new long long[N+1];
 
  noOfDivisors[0] = 0;
  noOfDivisors[1] = 1;
 
  for(int i=2; i<N+1; i++)
  {
    noOfDivisors[i] = 1;
  }
 
  for(int i=2; i<=N; i++)
  {
    if(!isPrime[i])
    {
      continue;
    }
 
    noOfDivisors[i] = 2;
 
    for(int j=2*i; j<=N; j+=i)
    {
      isPrime[j] = false;
 
      int no = j;
      int ans = 0;
 
      while(no%i == 0)
      {
        ans++;
        no/=i;
      }
 
      noOfDivisors[j] *= (ans+1);
    }
  }
 
  cout << endl;
  vector<int>* edges = new vector<int>[N+1];
 
  for(int i=0; i<N-1; i++)
  {
    int a, b;
    cin >> a >> b;
 
    edges[a].push_back(b);
    //edges[b].push_back(a);
  }
 
 
 
  int exclusive = calcStrength(edges, noOfDivisors, 1, 0, 1);
 
  cout << exclusive << endl;
 
  delete[] noOfDivisors;  
  delete[] edges;
 
  return 0;
}
