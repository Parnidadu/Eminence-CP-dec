// this progarm prints all possible substring of a string ..try it once and you feel the power of recursion;

#include <iostream>
using namespace std;
void print_sub(string input,string output){
	if(input.empty()){
		cout<<output<<endl;
		return;
	}
	print_sub(input.substr(1),output);
	print_sub(input.substr(1),output+input[0]);
}

int main() {
	// your code goes here
	string input;
	cin>>input;
	string output;
	print_sub(input,"");
	return 0;
}
