// P-2-15. 圓環出口 (APCS202007)
#include <bits/stdc++.h>
using namespace std;

int p[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q, room = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> p[i];
    for (int i = 1; i < n; ++i) p[i] += p[i - 1];   // prefix sum

    int total = p[n - 1];
    for (int i = 0; i < m; i++) {
        cin >> q;
        if (room != 0) q += p[room - 1];
        if (q > total) room = 0, q -= total;
        room = ((lower_bound(p, p + n, q) - p) + 1) % n;
    }
    cout << room;
    return 0;
}