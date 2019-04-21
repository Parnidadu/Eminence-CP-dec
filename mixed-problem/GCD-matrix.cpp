#include <bits/stdc++.h>
using namespace std;

const int N = int(1e5) + 5;

int a[N], b[N];
int ca[N], cb[N];
long long cnt[N];

int main() {
    int n, m, q;
    assert(scanf("%d%d%d", &n, &m, &q) == 3);

    for (int i = 0; i < n; ++i) {
        assert(scanf("%d", &a[i]) == 1);
        assert(1 <= a[i] && a[i] <= int(1e5));
    }
    for (int i = 0; i < m; ++i) {
        assert(scanf("%d", &b[i]) == 1);
        assert(1 <= b[i] && b[i] <= int(1e5));
    }

    for (int it = 0; it < q; ++it) {
        int a, b, c, d;
        assert(scanf("%d%d%d%d", &a, &b, &c, &d) == 4);
        ++a, ++b, ++c, ++d;
        memset(ca, 0, sizeof(ca));
        memset(cb, 0, sizeof(cb));
        for (int i = a - 1; i < c; ++i)
            ca[::a[i]]++;
        for (int i = b - 1; i < d; ++i)
            cb[::b[i]]++;
        for (int i = 1; i < N; ++i)
            for (int j = i + i; j < N; j += i) {
                ca[i] += ca[j];
                cb[i] += cb[j];
            }
        int res = 0;
        for (int i = N - 1; i >= 1; --i) {
            cnt[i] = ca[i] * 1ll * cb[i];
            for (int j = i + i; j < N; j += i)
                cnt[i] -= cnt[j];
            if (cnt[i])
                res++;
        }
        printf("%d\n", res);
    }
    return 0;
}
