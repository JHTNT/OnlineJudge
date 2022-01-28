#include <iostream>
using namespace std;

int get_len(int n) {
    // 計算經過運算到 1 所需的次數
    int count = 1;
    while (n != 1) {
        if (n % 2 == 1)
            n = n * 3 + 1;
        else
            n /= 2;
        count++;
    }
    return count;
}

int main() {
    int m, n;
    while (cin >> m >> n) {
        int max_len = 0;
        cout << m << " " << n << " ";
        if (n < m) swap(m, n);          // 保持 m 為較小的值
        for (int i = m; i <= n; i++) {
            max_len = max(max_len, get_len(i));         // 取得最長的循環次數
        }
        cout << max_len << endl;
    }
    return 0;
}