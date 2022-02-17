#include <iostream>
using namespace std;

int p[1000005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // 質數建表
    p[1] = 1;       // 值為 0 代表質數，1 代表合數
    for (int i = 2; i < 1000005; i++) {
        if (p[i] == 0) {
            // 從 i * 2 開始，雖然效率低但好寫
            for (int j = i + i; j < 1000005; j += i) {
                p[j] = 1;
            }
        }
    }
    int n, x, y;
    while (cin >> n) {
        x = n, y = 0;
        while (x) {         // 反轉 n
            y *= 10;
            y += x % 10;
            x /= 10;
        }
        if (p[n]) {
            cout << n << " is not prime.\n";
        } else if (n != y && !p[y]) {
            cout << n << " is emirp.\n";
        } else {
            cout << n << " is prime.\n";
        }
    }
    return 0;
}