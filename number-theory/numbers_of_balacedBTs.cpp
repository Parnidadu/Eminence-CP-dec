
int balancedBTs(int h) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return the output and don’t print it.
  */
  if(h == 0 || h == 1){
    return 1;
  }
  else{
    int m = 1000000007;
    int x = balancedBTs(h-1);
    int y = balancedBTs(h-2);
    long res1 = (long) x*x;
    long res2 = (long) 2*x*y;
    int ans1 = (int) (res1%m);
    int ans2 = (int) (res2%m);
    return (ans1+ans2)%m;
  }

}
#include <iostream>
using namespace std;
#include <cmath>

int main() {
    int h;
    cin >> h;
    int ans = balancedBTs(h);
    cout << ans << endl;
}
