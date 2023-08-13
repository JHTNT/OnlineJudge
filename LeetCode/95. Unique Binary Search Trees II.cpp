#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    vector<TreeNode *> generateTrees(int n) {
        vector<vector<vector<TreeNode *>>> dp(n + 1, vector(n + 1, vector<TreeNode *>(0)));
        for (int i = 1; i <= n; i++) {
            dp[i][i].push_back(new TreeNode(i));
        }

        for (int numberOfNodes = 2; numberOfNodes <= n; numberOfNodes++) {
            for (int start = 1; start <= n - numberOfNodes + 1; start++) {
                int end = start + numberOfNodes - 1;
                for (int i = start; i <= end; i++) {
                    vector<TreeNode *> leftSubtrees =
                        i - 1 >= start ? dp[start][i - 1] : vector<TreeNode *>({nullptr});
                    vector<TreeNode *> rightSubtrees =
                        i + 1 <= end ? dp[i + 1][end] : vector<TreeNode *>({nullptr});

                    for (auto left : leftSubtrees) {
                        for (auto right : rightSubtrees) {
                            TreeNode *root = new TreeNode(i, left, right);
                            dp[start][end].push_back(root);
                        }
                    }
                }
            }
        }
        return dp[1][n];
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}