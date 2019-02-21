#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int max(int *arr, int a){
  int max = arr[0];
  for(int i=1;i<a;i++){
    if(arr[i]>max){
      max = arr[i];
    }
  }
  return max;
}
int main()
{
  	//write  your code here
  int test;
  cin >> test;
  while(test--){
    int N,M;
    cin >> N >> M;
    long *capacity = new long[M];
    long *weight = new long[N];
    long *numberofcakes = new long[N];
    for(int i= 0;i<M;i++){
      cin >> capacity[i];
    }
    sort(capacity,capacity+M)
    for(int i= 0;i<N;i++){
      cin >> weight[i];
    }
    for(int i= 0;i<N;i++){
      cin >> numberofcakes[i];
    }
    int max1 = max(capacity,M);
    int max2 = max(weight,N);
    if(max2 > max1){
      cout<<"-1"<<endl;
    }
    else{
      
    }
    
  }
    return 0;
}
