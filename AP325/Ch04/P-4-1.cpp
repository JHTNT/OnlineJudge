// P-4-1. 少林寺的代幣
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n;
    int coins[4] = {1, 5, 10, 50};

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> n;
        int ans = 0;
        for (int j = 3; j >= 0; j--) {
            ans += n / coins[j];
            n %= coins[j];
        }
        cout << ans << "\n";
    }
    return 0;
}
