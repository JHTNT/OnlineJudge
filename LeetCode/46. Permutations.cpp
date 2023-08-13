#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr = {};
        backtrack(curr, ans, nums);
        return ans;
    }

   private:
    void backtrack(vector<int>& curr, vector<vector<int>>& ans, vector<int>& nums) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int num : nums) {
            if (find(curr.begin(), curr.end(), num) == curr.end()) {  // num not in curr
                curr.push_back(num);
                backtrack(curr, ans, nums);
                curr.pop_back();
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    vector<vector<int>> ans = Solution().permute(nums);
    for (vector<int> i : ans) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}