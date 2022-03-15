#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // 建表
    int square[4][50], count[4] = {0}, n, m;
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 10000; j++) {
            int m = 10;
            for (int k = 0; k < 4; k++, m *= 10) {
                // i ÷ m 用於確認是否超過 k + 1 位數
                if (pow(i + j, 2) == i * m + j && i / m == 0 && j / m == 0) {
                    square[k][count[k]++] = i * m + j;
                }
            }
        }
    }

    while (cin >> n) {
        m = n / 2 - 1;
        cout << setfill('0');
        for (int i = 0; i < count[m]; i++) {
            cout << setw(n) << square[m][i] << "\n";
        }
    }
    return 0;
}