// Q-3-13. X 差值範圍內的最大 Y 差值
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, l, ans = 0;
    deque<int> max_q, min_q;
    cin >> n >> l;
    vector<vector<int>> seq(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++) cin >> seq[i][0];
    for (int i = 0; i < n; i++) cin >> seq[i][1];

    sort(seq.begin(), seq.end());
    max_q.push_back(0), min_q.push_back(0);
    for (int i = 1; i < n; i++) {
        if (seq[i][0] - seq[max_q.front()][0] > l) max_q.pop_front();  // out of range
        while (!max_q.empty() && seq[max_q.back()][1] <= seq[i][1]) max_q.pop_back();
        max_q.push_back(i);

        if (seq[i][0] - seq[min_q.front()][0] > l) min_q.pop_front();  // out of range
        while (!min_q.empty() && seq[min_q.back()][1] >= seq[i][1]) min_q.pop_back();
        min_q.push_back(i);

        int diff = seq[max_q.front()][1] - seq[min_q.front()][1];
        ans = max(ans, diff);
    }
    cout << ans;
    return 0;
}
