/*Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. 
Write a program to print the list of all possible codes that can be generated from the given string.*/


#include <string.h>
using namespace std;
char hashmap[]={'\0','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

void print(string input, string output){
  if(input.empty()){
    cout<<output<<endl;
    return;
  }
  for(int i=1;i<3;i++){
    string temp=input.substr(0,i);
    int tem= stoi(temp);
    
    int len=input.length();
	    if(len>=i && tem<=27){
	    print(input.substr(i),output+hashmap[tem]);
	    }
  }
  
}

void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
  print(input,"");
}

int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
