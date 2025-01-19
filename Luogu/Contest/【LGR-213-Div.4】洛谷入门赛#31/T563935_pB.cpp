#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, x, y;
    cin >> a >> b;

    if (a % 2 == b % 2) {
        cout << abs(a - b) / 2 - 1;
    } else {
        if (a % 2) {
            x = (a - 1) / 2;
            y = b / 2;
        } else {
            x = a / 2;
            y = (b - 1) / 2;
        }
        cout << x + y;
    }
    return 0;
}
