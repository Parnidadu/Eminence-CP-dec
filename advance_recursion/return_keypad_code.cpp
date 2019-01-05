/*Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.*/

#include<string>
const char key[10][5]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
using namespace std;

int keypad(int n, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
  if(n==0){
		output[0]="";
		return 1;
	}
	int temp=n%10;
	n=n/10;
	int ans= keypad(n,output);
	int j=-1;
	int ret=0;
	string tem[ans];
	for(int i=0;i<ans;i++){
		tem[i]=output[i];
	}
	while(key[temp][++j]!='\0'){
		
		for(int i=0;i<ans;i++){
			output[ret+i]= tem[i]+key[temp][j];
			//cout<<key[temp][j]<<" ";
		}
		ret=ret+ans;
	}
	return ret;
  
}
