#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int remain = 0, saved = 0, cost;
    bool enough = true;

    for (int i = -1; i >= -12; i--) {
        cin >> cost;
        if (!enough) continue;

        remain += 300;
        if (remain - cost < 0) {
            cout << i << "\n";
            enough = false;
        }
        remain -= cost;
        saved += remain / 100 * 100;
        remain %= 100;
    }

    if (enough) cout << saved * 1.2 + remain;
    return 0;
}
