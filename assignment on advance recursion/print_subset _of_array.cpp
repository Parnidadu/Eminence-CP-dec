
#include<bits/stdc++.h>
using namespace std;
void printSubsetsOfArray(int input[], int size) {
	// Write your code here
  int  count = pow(2,size);
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < size; j++)
		{
			// This if condition will check if jth bit in binary representation of  i  is set or not
			// if the value of (i & (1 << j)) is greater than 0 , include arr[j] in the current subset
			// otherwise exclude arr[j]
			if ((i & (1 << j)) > 0)
				cout << input[j] << " ";
		}
		cout << "\n";
	}
    
}
int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}
