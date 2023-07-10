// P-3-8. 固定長度區間的最大區段差
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, l, seq[200005], ans = 0;
    deque<int> max_q, min_q;
    cin >> n >> l;
    for (int i = 0; i < n; i++) cin >> seq[i];

    max_q.push_back(0), min_q.push_back(0);
    for (int i = 1; i < n; i++) {
        if (max_q.front() <= i - l) max_q.pop_front();   // out of range
        while (!max_q.empty() && seq[max_q.back()] <= seq[i]) max_q.pop_back();
        max_q.push_back(i);

        if (min_q.front() <= i - l) min_q.pop_front();   // out of range
        while (!min_q.empty() && seq[min_q.back()] >= seq[i]) min_q.pop_back();
        min_q.push_back(i);

        int diff = seq[max_q.front()] - seq[min_q.front()];
        ans = max(ans, diff);
    }
    cout << ans;
    return 0;
}
