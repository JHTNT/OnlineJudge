// P-4-4. 幾場華山論劍 (activity selection)
#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second > b.second) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    vector<pair<int, int>> events(n);
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        events[i] = {end, start};  // sort by end time
    }

    int lastend = -1, ans = 0;
    sort(events.begin(), events.end());
    for (auto e : events) {
        if (e.second > lastend) {
            lastend = e.first;
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
