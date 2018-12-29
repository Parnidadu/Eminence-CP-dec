#include<algorithm>
#include<vector>
int kthLargest (std::vector<int> arr, int n, int k){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
  int temp;
  sort(arr.begin(),arr.end());
  std::vector<int>::iterator it;
  it=arr.end();
  while(k--)
    temp=*(it--);
  temp=*(it--);
  return temp;
    
}
