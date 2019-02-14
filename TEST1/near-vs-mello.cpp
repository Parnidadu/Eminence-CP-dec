#include <iostream>
#include<algorithm>
using namespace std;

int main(){
	int n;
  	cin >> n;
  	long *height = new long[n];
  	for(int i=0;i<n;i++){
      cin >> height[i];
    }
  	sort(height,height+n);
  	long first,last,length,breadth;
  	long volume;
  	first = height[n-1];
  	last = height[n-2];
  	if(first > last){
      length = last;
    }
  	else{
      length = first;
    }
  	volume = length*(n-2);
	for(int i=0;i<n-2;i++){
      volume = volume - height[i];
    }	  
  cout << volume;
	return 0;
}
