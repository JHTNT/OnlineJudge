// P-1-1. 合成函數(1)
#include <bits/stdc++.h>
using namespace std;

int eval() {
    char c;
    int x, y, n;
    if (cin >> n && cin) return n;
    cin.clear();    // reset cin status when cin failed
    cin >> c;
    if (c == 'f') {
        x = eval();
        return 2 * x - 1;
    } else if (c == 'g') {
        x = eval();
        y = eval();
        return x + 2 * y - 3;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << eval();
    return 0;
}