#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while ((a %= b) && (b %= a)) {}
    return a + b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n) {
        if (n == 0) break;
        int g = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                g += gcd(i, j);
            }
        }
        cout << g << "\n";
    }
    return 0;
}