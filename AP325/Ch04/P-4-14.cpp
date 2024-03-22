// P-4-14. 控制點 (2D-max)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) cin >> points[i].first;   // x
    for (int i = 0; i < n; i++) cin >> points[i].second;  // y
    sort(points.begin(), points.end());

    int ans = 0, max_y = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (points[i].second > max_y) {
            max_y = points[i].second;
            ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}
