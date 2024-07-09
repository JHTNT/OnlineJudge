#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double k, n = 1, S = 1;
    cin >> k;
    while (S <= k) {
        n++;
        S += 1 / n;
    }
    cout << n << "\n";
    return 0;
}
