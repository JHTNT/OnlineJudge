// P-4-11. 線段聯集 (APCS 201603)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    vector<pair<int, int>> lines(n);    // first: left, second: right
    for (int i = 0; i < n; i++) cin >> lines[i].first >> lines[i].second;
    sort(lines.begin(), lines.end());

    int total = 0;
    pair<int, int> last = lines[0];
    for (int i = 1; i < n; i++) {
        if (lines[i].first > last.second) {
            total += last.second - last.first;
            last = lines[i];
            continue;
        }
        last.second = max(lines[i].second, last.second);
    }
    total += last.second - last.first;

    cout << total << "\n";
    return 0;
}
