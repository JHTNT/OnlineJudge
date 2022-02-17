#include <iostream>
using namespace std;

int sum(int n) {
    int s = 0;
    while (n) {
        s += n % 10;
        n /= 10;
    }
    if (s < 10) {
        return s;
    } else {
        return sum(s);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n) {
        if (n == 0) break;
        cout << sum(n) << "\n";
    }
    return 0;
}

/* 另解
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    while (cin >> n && n) {
        while (n / 10) n = n / 10 + n % 10;
        cout << n << "\n";
    }
    return 0;
}
*/