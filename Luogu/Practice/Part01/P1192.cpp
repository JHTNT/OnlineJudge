#include <bits/stdc++.h>
using namespace std;

int cnt[100005] = {1, 1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= min(i, k); j++) {
            // i = j 時，有 cnt[0] = 1 種走法
            cnt[i] = (cnt[i] + cnt[i - j]) % 100003;
        }
    }
    cout << cnt[n] % 100003;
    return 0;
}
