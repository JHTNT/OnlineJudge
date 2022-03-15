/*
約瑟夫問題
嘗試每個 m 值，先簡化到 1 個區域後，回推到 N 個區域。
題目需要的區域為 13，但第一個區域會先停電所以 -1，從 0 開始計算再 -1。
*/
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, m, cnt;
    while (cin >> N) {
        if (N == 0) break;
        m = 0, N--;        // 第一個區域停電
        while (++m) {       // m 有可能大於 N
            cnt = 0;
            for (int i = 1; i <= N; i++) {
                cnt = (cnt + m) % i;        // 公式解
            }
            if (cnt == 11) break;
        }
        cout << m << "\n";
    }
    return 0;
}