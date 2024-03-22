// P-4-13. 最大連續子陣列
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    long long max_sum = 0, max_prefix = 0;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        max_prefix = (max_prefix > 0) ? max_prefix + p : p;
        max_sum = max(max_sum, max_prefix);
    }

    cout << max_sum << "\n";
    return 0;
}
