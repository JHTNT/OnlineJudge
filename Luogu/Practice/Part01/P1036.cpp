#include <bits/stdc++.h>
using namespace std;

int n = 0, k = 0, ans = 0;
int nums[25];
unordered_set<int> sums;

bool check_prime(int n) {
    if (n == 2) return true;
    if (n == 1 || n % 2 == 0) return false;

    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

void dfs(int startIdx, int cnt, int S) {
    if (cnt == k) {
        if (check_prime(S)) ans++;
        return;
    }

    for (int i = startIdx; i < n; i++) {
        dfs(i + 1, cnt + 1, S + nums[i]);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> nums[i];
    dfs(0, 0, 0);
    cout << ans;
    return 0;
}
