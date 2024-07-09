#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x, y, max_mad = 0, day = 0;
    for (int i = 1; i <= 7; i++) {
        cin >> x >> y;
        if (x + y < 8) continue;

        int mad = x + y - 8;
        if (mad > max_mad) {
            max_mad = mad;
            day = i;
        }
    }
    cout << day << "\n";
    return 0;
}
