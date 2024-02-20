// P-4-7. 岳不群的併派問題 (Two-way merge)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        pq.push(m);
    }

    long long cost;
    for (int i = 0; i < n - 1; i++) {
        long long curr = pq.top();
        pq.pop();
        curr += pq.top();
        pq.pop();
        pq.push(curr);
        cost += curr;
    }
    cout << pq.top() << "\n" << cost << "\n";
    return 0;
}
