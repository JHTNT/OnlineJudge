#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, ans = 0;
    cin >> n;
    while (n != 0) {
        ans = ans * 10 + n % 10;
        n /= 10;
    }
    cout << ans;
    return 0;
}
