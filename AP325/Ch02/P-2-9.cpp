// P-2-9. 子集合乘積(折半枚舉)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void rec(vector<LL> &v, int i, LL prod, map<LL, LL> &mp, int p) {
    if (i == v.size()) {
        mp[prod]++;
        return;
    }
    rec(v, i + 1, prod * v[i] % p, mp, p);
    rec(v, i + 1, prod, mp, p);
    return;
}

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
    int n, p, i;
    LL tmp;
    vector<LL> a, b;
    cin >> n >> p;
    for (i = 0; i < n / 2; i++) {
        cin >> tmp;
        a.push_back(tmp);
    }
    for (; i < n; i++) {
        cin >> tmp;
        b.push_back(tmp);
    }

    map<LL, LL> mp1, mp2;
    rec(a, 0, 1, mp1, p);
    rec(b, 0, 1, mp2, p);
    mp1[1]--, mp2[1]--;     // remove empty set
    LL ans = (mp1[1] + mp2[1]) % p;     // no need to process product 1
    for (auto e : mp1) {
        LL mmi = exp(e.first, p - 2, p);
        auto it = mp2.find(mmi);
        if (it != mp2.end())
            ans = (ans + e.second * it->second) % p;
    }
    cout << ans;
    return 0;
}