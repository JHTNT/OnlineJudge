// P-2-3. 快速冪
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL exp(LL x, LL y, LL p) {
    if (y == 0) return 1;
    if (y & 1) return (exp(x, y - 1, p) * x) % p;
    LL t = exp(x, y / 2, p);
    return (t * t) % p;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    LL x, y, p;
    cin >> x >> y >> p;
    cout << exp(x, y, p);
    return 0;
}