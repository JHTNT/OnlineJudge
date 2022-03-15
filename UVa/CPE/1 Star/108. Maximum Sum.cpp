/*
在輸入的同時計算每列的前綴和，
則 j - i 就是第 i + 1 項到第 j 項的和。
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, num[105][105], total, ans;
    while (cin >> N) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> num[i][j];
                num[i][j] += num[i][j - 1];         // 計算前綴和
            }
        }
        ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j <= N; j++) {
                total = 0;
                for (int k = 1; k <= N; k++) {      // 移動列
                    total += num[k][j] - num[k][i];
                    ans = max(total, ans);
                    if (total < 0) total = 0;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}