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
    vector<TreeNode *> allPossibleFBT(int n) {
        if (n % 2 == 0) return {};

        vector<vector<TreeNode *>> dp(n + 1);
        dp[1].push_back(new TreeNode(0));

        for (int count = 3; count <= n; count += 2) {
            for (int i = 1; i < count - 1; i += 2) {
                int j = count - i - 1;
                for (TreeNode *left : dp[i]) {
                    for (TreeNode *right : dp[j]) {
                        TreeNode *root = new TreeNode(0, left, right);
                        dp[count].push_back(root);
                    }
                }
            }
        }

        return dp[n];
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}