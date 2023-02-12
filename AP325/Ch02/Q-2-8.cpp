// Q-2-8. 模逆元
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL exp(LL x, LL y, int p) {
    LL t = 1, xi = x;
    while (y > 0) {
        if (y & 1) t = (t * xi) % p;
        y >>= 1;
        xi = (xi * xi) % p;
    }
    return t;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, p, a;
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        cin >> a;
        cout << exp(a, p - 2, p) << " ";
    }
    return 0;
}