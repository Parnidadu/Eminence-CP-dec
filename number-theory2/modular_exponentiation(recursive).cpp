#include <iostream>
using namespace std;
#define c 1000000009
int modRec(int a,int b){
	if(b==0){
		return 1;
	}
	if(b%2==0){
		return modRec((a*a)%c,b/2);
	}
	else{
		return ((a%c)*modRec((a*a)%c,(b-1)/2))%c;
}
int main() {
	// your code goes here
	int a,b;
	cin >> a >> b;
	cout << modRec(a,b);
	return 0;
}
