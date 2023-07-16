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
    int minDepth(TreeNode *root) {
        if (root == NULL) return 0;

        int depth = 1;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                TreeNode* node = q.front(); q.pop();
                if (node->left == NULL && node->right == NULL) {
                    return depth;
                }

                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
            }
            depth++;
        }
        return 0;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}