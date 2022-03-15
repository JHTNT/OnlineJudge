#include <iostream>
#include <string>
#include <set>
using namespace std;

int N;

inline int convert(int x, int y) {
    return x * N + y;       // 將二維座標轉換成一維
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> N) {
        if (N == 0) break;
        int player = 0, winner = -1, turn, x, y;
        char act;
        set<string> pattern;
        string grid(N * N, '0');    // 用來儲存狀態
        string grid90(grid);        // 其他三個方向
        string grid180(grid);
        string grid270(grid);

        for (int i = 1; i <= N * 2; i++) {
            cin >> x >> y >> act;
            if (winner != -1) continue;

            x--, y--;       // 讓座標從 0, 0 開始
            if (act == '+') {
                grid[convert(x, y)] = '1';
            } else {
                grid[convert(x, y)] = '0';
            }
            if (pattern.find(grid) != pattern.end()) {
                winner = 1 - player, turn = i;      // 重複則另一個玩家獲勝
            } else {        // 紀錄旋轉後的樣式
                grid90[convert(N - 1 - y, x)] = grid180[convert(N - 1 - x, N - 1 - y)]
                                              = grid270[convert(y, N - 1 - x)]
                                              = grid[convert(x, y)];
                pattern.insert(grid);
                pattern.insert(grid90);
                pattern.insert(grid180);
                pattern.insert(grid270);
            }
            player = 1 - player;        // 兩個玩家輪流
        }
        if (winner != -1) {
            cout << "Player " << winner + 1 << " wins on move " << turn << "\n";
        } else {
            cout << "Draw\n";
        }
    }
    return 0;
}