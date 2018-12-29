#include<iostream>
#include<cstring>
#include<map>
using namespace std;


char nonRepeatingCharacter(string str){
  
  //Write your code here
  map<char,int> freq;
  for(int i=0;i<str.length();i++){
    char character=str[i];
    freq[character]++;
  }
  for(int i=0;i<str.length();i++){
    if(freq[str[i]]==1)
      return str[i];
  }
return str[0];
}


int main(){
  string str;
  char *p;
  cin>>str;
  p=nonRepeatingCharacter(str);
  cout<<p;

return 0;
}
