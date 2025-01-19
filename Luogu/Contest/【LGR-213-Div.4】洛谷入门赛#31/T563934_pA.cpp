#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    a = a % 10;
    if (a == b) {
        cout << 0;
    } else if (a < b) {
        cout << b - a;
    } else {
        cout << 10 + b - a;
    }
    return 0;
}
