#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a1, a2, n;
    cin >> a1 >> a2 >> n;

    int d = a2 - a1;
    long long ans = (a1 + (a1 + (n - 1) * d)) * n / 2;
    cout << ans;
    return 0;
}
