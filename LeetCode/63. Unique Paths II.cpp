#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(2, vector<int>(n + 1));
        dp[0][1] = 1;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (obstacleGrid[i - 1][j - 1] == 0)
                    dp[i & 1][j] = dp[(i - 1) & 1][j] + dp[i & 1][j - 1];
                else
                    dp[i & 1][j] = 0;
            }
        }
        return dp[m & 1][n];
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    vector<vector<int>> obstacleGrid(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> obstacleGrid[i][j];
    cout << Solution().uniquePathsWithObstacles(obstacleGrid);
    return 0;
}