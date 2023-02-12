// Q-2-5. 快速計算費式數列第 n 項
#include <bits/stdc++.h>
using namespace std;

int P = 1000000007;

pair<long long, long long> fib(int n) {
    if (n == 0) return {0, 1};
    auto p = fib(n >> 1);   // p.first = f(n), p.second = f(n + 1)
    int c = (2 * p.second - p.first) % P;
    if (c < 0) c += P;
    c = (p.first * c) % P;
    int d = (p.first * p.first + p.second * p.second) % P;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n) {
        if (n == -1) break;
        cout << fib(n).first << "\n";
    }
    return 0;
}