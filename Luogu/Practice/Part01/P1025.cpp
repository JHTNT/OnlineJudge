#include <bits/stdc++.h>
using namespace std;

int n, k, ans = 0;

void dfs(int last, int sum, int cnt) {
    if (cnt == k) {
        if (sum == n) ans++;
        return;
    }

    for (int i = last; sum + i * (k - cnt) <= n; i++) {
        dfs(i, sum + i, cnt + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    if (k == 1) {
        ans = 1;
    } else {
        dfs(1, 0, 0);
    }
    cout << ans;
    return 0;
}
