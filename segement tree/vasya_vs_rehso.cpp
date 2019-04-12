#include<bits/stdc++.h>
using namespace std;
 
#define all(C) C.begin(),C.end()
#define csize(C) int(C.size())
typedef long long int Long;
typedef long double Double;
const int MAXN = 1e6 + 1;
const int MAXLG = log2(MAXN) + 1;
 
struct Warrior {
  int a, b, i;
  Warrior() {}
  bool operator<(const Warrior &o) const {
    // this < o
    // =>
    // o > this
 
    if(o.a != a) {
      return o.a > a;
    }
    if(o.b != b) {
      return o.b < b;
    }
    return o.i < i;
  }
};
 
int n, q, L, R;
Warrior T[MAXLG][MAXN];
 
void build_sparse_table() {
  for(int j = 1; j < MAXLG; ++j)
    for(int i = 1; i + (1 << (j - 1)) <= n; ++i)
      T[j][i] = max(T[j - 1][i], T[j - 1][i + (1 << (j - 1))]);
}
 
Warrior get(int L, int R) {
  int k = (int) log2(R - L + 1);
  return max(T[k][L], T[k][R - (1 << k) + 1]);
}
 
int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    scanf("%d", &T[0][i].a);
  }
  for(int i = 1; i <= n; ++i) {
    scanf("%d", &T[0][i].b);
    T[0][i].i = i;
  }
 
  build_sparse_table();
 
  scanf("%d", &q);
  while(q--) {
    scanf("%d%d", &L, &R);
    printf("%d\n", get(L, R).i);
  }
  
  return 0;
}
