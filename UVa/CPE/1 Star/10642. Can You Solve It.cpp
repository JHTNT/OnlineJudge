/*
可將座標移動方式如下方所示：
          (0, 0) ->
     (0, 1) -> (1, 0) ->
(0, 2) -> (1, 1) -> (2, 0) -> ...

設 n = x + y，到 (x, y) 的距離為
2 + 3 + ... + n + (x + 1) = (n ^ 2 + n - 2) / 2
*/
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, x, y;
    long long n, a, b;      // n ^ 2 可能會超過 int 上限
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> x >> y;          // 起點
        if (x == 0 && y == 0) {
            a = 0;
        } else {
            n = x + y;
            a = (n * n + n - 2) / 2 + (x + 1);
        }

        cin >> x >> y;          // 終點
        if (x == 0 && y == 0) {
            b = 0;
        } else {
            n = x + y;
            b = (n * n + n - 2) / 2 + (x + 1);
        }
        cout << "Case " << i << ": " << b - a << "\n";
    }
    return 0;
}