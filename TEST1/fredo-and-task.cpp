#include <bits/stdc++.h>
using namespace std;

int main()
{
  	long max = 1000000000;
  	long n;
  	cin >> n;
  	double total = 0;
  	long *arr = new long[n];
    for(int i=0;i<n;i++){
      cin >> arr[i];
      total += log(arr[i]);
    }
     long start = 1;
     long end = max;
     long answer, mid;
     while (start <= end) {
         mid = (start + end) / 2;
         if (n * log(mid) > total) {
              end = mid - 1;
              answer = mid;
            } 
         else {
                start = mid + 1;
            }
		}
  	cout << answer;
  	
    return 0;
}
