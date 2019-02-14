
#include<iostream>
using namespace std;
bool subsetSumToKIdentical(int input[], int n, int k)
{
	/* Don't write main().
     * Don't read input, it is passed as function argument.
     * Taking input and printing output is handled automatically.
     */
  int total1 = k;
  int total2 = k;
  for(int i=0;i<n;i++){
    int num = input[i];
    while(input[i+1] == input[i]){
      i++;
    }
   total1 = total1 - num;
  }
  
  for(int i=0;i<n;i++){
    int temp = k - input[i];
    for(int j=0;j<n;j++){
      total2 = temp;
      if(i!=j){
        total2 = total2- input[j];
      }
    }
    if(total2==0){
      break;
    }
  }
  if(total1== 0 || total2== 0){
    return true;
  } 
  return false;
}
int main()
{
    int n;
    cin>>n;
    int arr[1000];
    for(int i = 0;i < n;i++)
        cin>>arr[i];
    int k;
    cin>>k;
    if(subsetSumToKIdentical(arr,n,k))
        cout<<"true";
    else cout<<"false";
}
