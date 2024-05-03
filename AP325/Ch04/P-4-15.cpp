// P-4-15. 最靠近的一對(closest pair) (@@)
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }

    sort(p.begin(), p.end());
    int min_dist = 200000001;
    multimap<int, int> mm;  // (y, x)
    for (int i = 0; i < n; i++) {
        auto it = mm.lower_bound(p[i].second - min_dist);
        while (it != mm.end() && it->first <= p[i].second + min_dist) {
            if (it->second < p[i].first - min_dist) {
                it = mm.erase(it);
                continue;
            }

            min_dist = min(min_dist, abs(p[i].first - it->second) + abs(p[i].second - it->first));
            it++;
        }
        mm.insert({p[i].second, p[i].first});
    }

    cout << min_dist << "\n";
    return 0;
}
