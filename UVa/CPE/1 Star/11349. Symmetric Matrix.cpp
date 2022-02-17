/*
O 表示未檢查，X 表示已檢查，以 3 階方陣為例：
OOO    XOO    XXO    XXX    XXX    XXX
OOO -> OOO -> OOO -> OOO -> XOX -> XXX
OOO    OOX    OXX    XXX    XXX    XXX
      i = 0  i = 0  i = 0  i = 1  i = 1
      j = 0  j = 1  j = 2  j = 0  j = 1
*/
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, T;
    bool symmetric;
    char c;
    cin >> T;
    for (int k = 1; k <= T; k++) {
        symmetric = true;
        cin >> c >> c >> n;
        long long matrix[n][n];         // 最多到 2^32，int 上限只到 2^31
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
                if (matrix[i][j] < 0) symmetric = false;
            }
        }
        cout << "Test #" << k;
        if (!symmetric) {
            cout << ": Non-symmetric.\n";
            continue;
        }
        for (int i = 0; i <= n / 2; i++) {      // 因為對稱所以只到中間列
            for (int j = 0; j < n - i; j++) {
                if (matrix[i][j] != matrix[n - i - 1][n - j - 1]) {
                    symmetric = false;
                    break;
                }
            }
            if (!symmetric) break;
        }
        if (symmetric) {
            cout << ": Symmetric.\n";
        } else {
            cout << ": Non-symmetric.\n";
        }
    }
    return 0;
}