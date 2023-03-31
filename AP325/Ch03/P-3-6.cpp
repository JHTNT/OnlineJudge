#include <bits/stdc++.h>
using namespace std;

// stack approaching
int main() {
    int n, l, c[100005], h[100005];
    int total = 0, highest = 0;
    stack<int> S;
    cin >> n >> l;
    c[0] = 0, c[n + 1] = l;
    h[0] = h[n + 1] = INT_MAX;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> h[i];

    S.push(0);
    for (int i = 1; i <= n; i++) {
        if (c[i] - h[i] >= c[S.top()] || c[i] + h[i] <= c[i + 1]) {
            total++;
            highest = max(highest, h[i]);
            while (c[S.top()] + h[S.top()] <= c[i + 1]) {
                total++;
                highest = max(highest, h[S.top()]);
                S.pop();
            }
        } else {
            S.push(i);
        }
    }
    cout << total << "\n" << highest;
    return 0;
}