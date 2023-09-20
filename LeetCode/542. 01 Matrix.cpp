#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;
        for (int row = 0; row < m; ++row)
            for (int column = 0; column < n; ++column)
                if (mat[row][column] == 0)
                    q.emplace(row, column);
                else
                    mat[row][column] = -1;  // marked as not processed yet

        while (!q.empty()) {
            auto [row, column] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nextR = row + direction[i], nextC = column + direction[i + 1];
                if (nextR < 0 || nextR == m || nextC < 0 || nextC == n || mat[nextR][nextC] != -1)
                    continue;
                mat[nextR][nextC] = mat[row][column] + 1;
                q.emplace(nextR, nextC);
            }
        }
        return mat;
    }

   private:
    vector<int> direction = {0, 1, 0, -1, 0};
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mat[i][j];
        }
    }
    vector<vector<int>> ans = Solution().updateMatrix(mat);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}