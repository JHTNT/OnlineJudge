// Q-4-16. 賺錢與罰款
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> order(n);
    for (int i = 0; i < n; i++) cin >> order[i].first;
    for (int i = 0; i < n; i++) cin >> order[i].second;

    sort(order.begin(), order.end());
    int t = 0;
    int ans = 0;
    for (auto o : order) {
        t += o.first;
        ans += o.second - t;
    }

    cout << ans << "\n";
    return 0;
}
