// P-4-9. 基地台
#include <bits/stdc++.h>
using namespace std;

int p[50005], n, k;

// check if the length of r is enough
bool check(int r) {
    int station = k, end = -1;
    for (int i = 0; i < n; i++) {
        if (p[i] <= end) continue;  // covered by base station
        if (station == 0) return false;

        end = p[i] + r;
        station--;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> p[i];
    sort(p, p + n);

    int len = 0, L = p[n - 1] - p[0];
    for (int jump = L / 2; jump > 0; jump >>= 1) {
        while (len + jump < L && !check(len + jump)) len += jump;
    }
    cout << len + 1 << "\n";
    return 0;
}
