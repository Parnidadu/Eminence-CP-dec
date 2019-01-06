/*Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
*/

#include <iostream>
#include <string>
using namespace std;
string output[1000];
const char key[10][5]={{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};

void helper(int n,string output){
  if(n==0){
   
    cout<<output<<endl;
    return;
  }
  
    int temp=n%10;
	n=n/10;
  	int j=-1;
  	while(key[temp][++j]!='\0'){
    helper(n,key[temp][j]+output); 
    }
  
  
}

void printKeypad(int n){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.

   */
 helper(n,"");
}
