#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int l, m;
    cin >> l >> m;
    vector<pair<int, int>> areas(m);
    for (int i = 0; i < m; i++) {
        cin >> areas[i].first >> areas[i].second;
    }

    sort(areas.begin(), areas.end());
    int trees = l + 1;
    pair<int, int> combined = areas[0];  // combine overlapping areas
    for (int i = 1; i < m; i++) {
        if (areas[i].first > combined.second) {
            trees -= combined.second - combined.first + 1;
            combined = areas[i];
            continue;
        }
        combined.second = max(areas[i].second, combined.second);
    }
    trees -= combined.second - combined.first + 1;

    cout << trees << "\n";
    return 0;
}
