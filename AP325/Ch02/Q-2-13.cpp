// Q-2-13. 無理數的快速冪 (108 高中全國賽, simplifed)
#include <bits/stdc++.h>
using namespace std;

int P = 1000000009;

pair<int, int> exp(int x, int y, int n) {
    long long s = 1, t = 0, xi = x, yi = y, tmp;
    while (n > 0) {
        if (n & 1) {
            tmp = (s * xi + t * yi * 2) % P;
            t = (s * yi + t * xi) % P;
            s = tmp;
        }
        n >>= 1;
        tmp = (xi * xi + yi * yi * 2) % P;
        yi = (xi * yi * 2) % P;
        xi = tmp;
    }
    return {s, t};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x, y, n;
    pair<int, int> ans;
    cin >> x >> y >> n;
    ans = exp(x, y, n);
    cout << ans.first << " " << ans.second;
    return 0;
}