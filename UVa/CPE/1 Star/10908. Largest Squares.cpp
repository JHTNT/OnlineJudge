/*
使用 DP 解決，從左上一路往右下邊輸入邊檢測，
如果左邊、左上、上面的字母相同，則最大正方形的邊長增加
處理後陣列表示從左上到該格最大正方形的邊長
範例：      處理後：
abbbaaa     1111111
abbbaaa     1122122
abbbaaa     1123123
aaaaaaa     1111123
*/
#include <iostream>
#include <cstring>          // memset
#include <algorithm>        // min
using namespace std;

int cnt[105][105];
char map[105][105];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, M, N, Q, r, c, ans;
    cin >> T;
    while (T--) {
        memset(map, '\0', sizeof(map));
        cin >> M >> N >> Q;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
                if (i == 0 || j == 0) {         // 避免上邊界與左邊界越界
                    cnt[i][j] = 1;
                } else if (map[i][j] == map[i - 1][j] &&
                           map[i][j] == map[i][j - 1] &&
                           map[i][j] == map[i - 1][j - 1]) {
                    cnt[i][j] = min({cnt[i - 1][j], cnt[i][j - 1],
                                    cnt[i - 1][j - 1]}) + 1;        // 記得大括號
                } else {
                    cnt[i][j] = 1;
                }
            }
        }
        cout << M << " " << N << " " << Q << "\n";
        while (Q--) {
            cin >> r >> c;
            ans = 1;
            for (int i = 1; i <= 100; i++) {
                if (r + i > M || c + i > N) {
                    break;
                } else if (cnt[r + i][c + i] >= ans + 2) {
                    ans += 2;
                } else {
                    break;
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}