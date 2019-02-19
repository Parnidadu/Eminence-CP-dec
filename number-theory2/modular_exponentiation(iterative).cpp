#include <iostream>
#define c 1000000009;
using namespace std;

int main() {
	// your code goes here
	//modular exponentiation
	int a,b;
	int ans = 1;
	cin >> a >> b;
	while(b!=0){
		if(b & 1){
			ans = (ans*a)%c;
		}
		a = (a*a)%c;
		b = b/2;
	}
	cout << ans;
	return 0;
}
