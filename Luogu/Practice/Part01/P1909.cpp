#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> pack(3);
    for (int i = 0; i < 3; i++) cin >> pack[i].first >> pack[i].second;

    int ans = INT_MAX;
    for (int i = 0; i < 3; i++) {
        int price = (n + pack[i].first - 1) / pack[i].first * pack[i].second;
        ans = min(ans, price);
    }
    cout << ans << "\n";
    return 0;
}
