// Q-4-17. 死線高手
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, n;
    cin >> T;

    while (T--) {
        cin >> n;
        vector<pair<int, int>> work(n);
        for (int i = 0; i < n; i++) cin >> work[i].second;  // time
        for (int i = 0; i < n; i++) cin >> work[i].first;   // deadline

        sort(work.begin(), work.end());
        int time = 0;
        bool can_finish = true;
        for (auto w : work) {
            time += w.second;
            if (time > w.first) {
                can_finish = false;
                break;
            }
        }

        cout << (can_finish ? "yes\n" : "no\n");
    }
    return 0;
}
