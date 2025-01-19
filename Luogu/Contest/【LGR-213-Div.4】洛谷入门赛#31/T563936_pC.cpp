#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x1, c, k;
    cin >> x1>> c >> k;

    for (int i = 0; i < k - 1; i++) {
        x1 = (x1 * x1 + c) % 10000;
    }
    cout << x1;
    return 0;
}
