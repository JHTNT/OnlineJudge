// Q-2-10. 子集合的和(折半枚舉)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL p;

void rec(vector<LL> &v, set<LL> &s, int i, LL sum) {
    if (sum > p) return;
    if (i == v.size()) {
        s.insert(sum);
        return;
    }
    rec(v, s, i + 1, sum + v[i]);
    rec(v, s, i + 1, sum);
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, i;
    LL tmp, MAX = 0, cnt = 0;
    vector<LL> a, b;
    set<LL> s1, s2;
    cin >> n >> p;
    for (i = 0; i < n / 2; i++) {
        cin >> tmp;
        a.push_back(tmp);
    }
    for (; i < n; i++) {
        cin >> tmp;
        b.push_back(tmp);
    }
    rec(a, s1, 0, 0);
    rec(b, s2, 0, 0);
    for (LL e : s1) {
        tmp = e + *(prev(s2.lower_bound(p - e)));
        MAX = max(MAX, tmp);
    }
    cout << MAX;
    return 0;
}