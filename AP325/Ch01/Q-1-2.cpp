// Q-1-2. 合成函數(2) (APCS201902)
#include <bits/stdc++.h>
using namespace std;

int eval() {
    char c;
    int x, y, z, n;
    if (cin >> n && cin) return n;
    cin.clear();
    cin >> c;
    if (c == 'f') {
        x = eval();
        return 2 * x - 3;
    } else if (c == 'g') {
        x = eval();
        y = eval();
        return 2 * x + y + 7;
    } else if (c == 'h') {
        x = eval();
        y = eval();
        z = eval();
        return 3 * x - 2 * y + z;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << eval();
    return 0;
}