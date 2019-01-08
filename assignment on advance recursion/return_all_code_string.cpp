/*Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S.
Write a program to return the list of all possible codes that can be generated from the given string.*/

#include <iostream>
#include <string.h>
using namespace std;
string hashmap[]={"","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
  if(input.empty()){
    output[0]="";
    return 1;
  }
  string newout[10000];
  int k=0;
  for(int i=1;i<3;i++){
    string temp=input.substr(0,i);
    //temp=input.substr(0,i);
    int tem=stoi(temp);
    int len=input.length();
    if(len>=i && tem<=27){
      int ans=getCodes(input.substr(i),newout);
      for(int j=0;j<ans;j++)
      	output[k++]=hashmap[tem] + newout[j];
    }
  }
  return k;
}

int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
