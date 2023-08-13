#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp{nums.begin(), nums.end()};

        for (int diff = 1; diff < n; diff++) {
            for (int left = 0; left < n - diff; left++) {
                // right = left + diff;
                dp[left] = max(nums[left] - dp[left + 1], nums[left + diff] - dp[left]);
            }
        }

        return dp[0] >= 0;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << Solution().PredictTheWinner(nums);
    return 0;
}