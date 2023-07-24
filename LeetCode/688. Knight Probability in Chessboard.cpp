#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    double knightProbability(int n, int k, int row, int column) {
        vector<pair<int, int>> directions = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                                             {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

        vector dp(k + 1, vector(n, vector<double>(n, 0.0)));
        dp[0][row][column] = 1;

        for (int moves = 1; moves <= k; moves++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (const auto &direction : directions) {
                        int prevI = i - direction.first;
                        int prevJ = j - direction.second;
                        if (prevI >= 0 && prevI < n && prevJ >= 0 && prevJ < n) {
                            dp[moves][i][j] += dp[moves - 1][prevI][prevJ] / 8;
                        }
                    }
                }
            }
        }

        double totalProbability = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                totalProbability += dp[k][i][j];
            }
        }
        return totalProbability;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, row, column;
    cin >> n >> k >> row >> column;
    cout << Solution().knightProbability(n, k, row, column);
    return 0;
}