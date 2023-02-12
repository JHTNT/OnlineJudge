// Q-2-4. 快速冪--200 位整數
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL exp(LL x, LL y, LL p) {
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
    LL x, y, p;
    string s;
    cin >> s >> y >> p;
    x = s[0] - '0';
    for (int i = 1; i < s.size(); i++)
        x = (x * 10 % p + s[i] - '0') % p;
    cout << exp(x, y, p);
    return 0;
}