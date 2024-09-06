#include <bits/stdc++.h>
using namespace std;

// Use recursive will TLE.

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> len(n + 1, 1);

    for (int i = 2; i <= n; i++) {
        for (int j = i / 2; j >= 1; j--) {
            len[i] += len[j];
        }
    }
    cout << len[n];
    return 0;
}
