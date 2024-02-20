// Q-3-14. 線性函數
#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> pll;

pair<double, double> get_point(pll p1, pll p2) {  // get intersection of two lines
    // ax + b = y, cx + d = y
    double x = (p1.second - p2.second) / (p2.first - p1.first);  // (b - d) / (c - a)
    double y = p1.first * x + p1.second;
    return {x, y};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pll> fn(n);
    vector<int> c(m);

    for (int i = 0; i < n; i++) cin >> fn[i].first >> fn[i].second;
    for (int i = 0; i < m; i++) cin >> c[i];

    int idx = 0;
    vector<pll> F(n);
    sort(fn.begin(), fn.end());
    for (auto p : fn) {
        while (idx >= 1) {
            if (F[idx - 1].first == p.first) {
                idx--;
            } else if (get_point(F[idx - 1], F[idx - 2]) < get_point(F[idx - 1], p)) {
                idx--;
            }
        }
        F[idx++] = p;
    }

    double points[idx];
    for (int i = 0; i < idx; i++) {
        points[idx] = get_point(F[idx], F[idx + 1]).first;
    }

    return 0;
}
