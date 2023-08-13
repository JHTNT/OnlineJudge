#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;

        while (left <= right) {
            int mid = (right + left) / 2;
            int value = matrix[mid / n][mid % n];

            if (value == target)
                return true;
            else if (value < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n, target;
    cin >> m >> n >> target;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[m][n];
        }
    }
    cout << boolalpha << Solution().searchMatrix(matrix, target);
    return 0;
}