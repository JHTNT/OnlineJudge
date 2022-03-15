#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x, y;
    double tmp;
    while (cin >> n) {
        x = tmp = (-1 + sqrt(1 + 8 * n)) / 2;
        if ((double) x == tmp) x--;
        y = n - (pow(x, 2) + x) / 2 - 1;
        if ((x + 1) % 2) {
            cout << "TERM " << n << " IS " << (x + 1) - y << "/" << y + 1 << "\n";
        } else {
            cout << "TERM " << n << " IS " <<  y + 1 << "/" <<(x + 1) - y << "\n";
        }
    }
    return 0;
}