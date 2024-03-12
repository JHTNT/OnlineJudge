// Q-4-8. 先到先服務
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    // fitst m customer
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        pq.push(t);
    }

    for (int i = 0; i < n - m; i++) {
        int t;
        cin >> t;

        int s = pq.top();
        pq.pop();
        s += t;
        pq.push(s);
    }
    for (int i = 0; i < m - 1; i++) pq.pop();
    cout << pq.top() << "\n";
    return 0;
}
