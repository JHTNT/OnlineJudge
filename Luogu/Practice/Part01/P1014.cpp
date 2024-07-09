#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, a;
    cin >> n;

    // x^2 + x - 2n = 0，公式解
    k = ceil((-1 + sqrt(1 + 8 * n)) / 2);
    a = n - (k - 1) * k / 2;
    if (k % 2) {
        cout << (k + 1 - a) << "/" << a << "\n";
    } else {
        cout << a << "/" << (k + 1 - a) << "\n";
    }
    return 0;
}
