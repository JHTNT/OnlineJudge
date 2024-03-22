// P-4-12. 一次買賣
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    int prefix_min = INT_MAX;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        ans = max(ans, p - prefix_min);
        prefix_min = min(p, prefix_min);
    }

    cout << ans << "\n";
    return 0;
}
