// Q-3-5. 帶著板凳排雞排的高人 (APCS201902)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, h[200005], p[200005];
    long long total = 0;
    multimap<int, int> mp;    // {height, index}
    h[0] = INT_MAX;

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++) cin >> p[i];

    for (int i = n; i >= 0; i--) {
        auto it = mp.begin();
        while (it != mp.end() && it->first < h[i]) {
            total += it->second - i - 1;
            it = mp.erase(it);
        }
        mp.insert({h[i] + p[i], i});
    }
    cout << total;
    return 0;
}