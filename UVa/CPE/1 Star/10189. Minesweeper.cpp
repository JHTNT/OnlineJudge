#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    char mine[105][105];
    int ans[105][105], n, m, x, y, count = 1;
    // 周圍八個方位的座標
    int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
    int dy[8] = {1, 0, -1, -1, -1, 0, 1, 1};
    while (scanf("%d %d", &n, &m)) {
        getchar();          // 去除緩存的換行符號
        if (n == 0 && m == 0) break;
        for (int i = 0; i < n; i++) {
            fgets(mine[i], m + 2, stdin);       // 包括換行符號共獲取 m + 1 個字元
        }
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mine[i][j] == '*') {
                    ans[i][j] = -1;
                } else {
                    for (int k = 0; k < 8; k++) {
                        x = i + dx[k];
                        y = j + dy[k];
                        if (x >= 0 && x < n && y >= 0 && y < m && mine[x][y] == '*') {
                            ans[i][j]++;
                        }
                    }
                }
            }
        }
        if (count > 1) printf("\n");
        printf("Field #%d:\n", count++);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ans[i][j] == -1) printf("*");
                else printf("%d", ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}