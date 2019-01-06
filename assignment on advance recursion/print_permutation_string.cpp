/*Given a string, find and print all the possible permutations of the input string.
Note : The order of permutations are not important. Just print them in different lines.
*/


#include <iostream>
#include<string>
using namespace std;

void print(string input,string output){
	 if(input.empty()){
    cout<<output<<endl;
    return;
  }
  int len=input.length();
  for (int i = 0; i < input.length(); i++) {
            char cc = input[i];
            print(input.substr(0,i)+input.substr(i+1), cc+output);

		}
}
void printPermutation(string input){
	print(input,"");
}
int main() {
	// your code goes here
	string input;
	cin>>input;
	printPermutation(input);
	return 0;
}
