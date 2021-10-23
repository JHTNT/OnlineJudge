#include <iostream>
using namespace std;

int main() {
    long int m, n;          // 範圍上限 2^32
    while (cin >> m >> n) {
        cout << abs(n - m) << endl;
    }
    return 0;
}