#include<iostream>
#include<vector>
#include<set>
using namespace std;


vector<int> removeDuplicates(vector<int> input){

    // Write your code here
  set<int> s;
  vector<int> result;
  for(int i=0;i<input.size();i++){
	if(s.find(input[i])==s.end()){
		s.insert(input[i]);
		result.push_back(input[i]);		
		}
	}
return result;
}


//this is optional lines of code for coding ninjas 
int main(){
	int n;
	cin>>n;
	vector<int> input(n);
	vector<int> result;
	for(int i=0;i<input.size();i++)
		cin>>input[i];
	result=removingDuplicates(input);
	for(int i=0;i<result.size();i++)
		cout<<result[i];
	return 0;
	
}
