// Q-2-12. 最接近的子矩陣和 (108 高中全國賽)
#include <bits/stdc++.h>
using namespace std;

int K, m, n, tmp, ans = 0;

int main() {
    clock_t s, e;
    s = clock();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    cin >> K >> m >> n;
    vector<vector<int>> ps(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> tmp;
            ps[i][j] = tmp + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
        }
    }

    for (int bottom = 1; bottom <= m; ++bottom) {
        for (int right = 1; right <= n; ++right) {
            for (int top = 0; top < bottom; ++top) {
                for (int left = 0; left < right; ++left) {
                    tmp = ps[bottom][right] + ps[top][left] - ps[bottom][left] - ps[top][right];
                    if (tmp < 0) break;
                    if (tmp <= K) ans = max(ans, tmp);
                }
            }
        }
    }
    cout << ans;
    e = clock();
    cout << "\n" << (double) (e - s) / CLOCKS_PER_SEC << " s";
    return 0;
}

// https://chengzhaoxi.xyz/d98d7741.html
// https://leetcode.cn/problems/max-submatrix-lcci/solution/qian-zhui-he-zui-da-zi-xu-he-by-dididudi-ozhw/