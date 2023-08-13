#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1);
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                dp[i + 1] |= dp[i - 1];
            }

            if (i > 1 && nums[i] == nums[i - 1] && nums[i] == nums[i - 2]) {
                dp[i + 1] |= dp[i - 2];
            }

            if (i > 1 && nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2) {
                dp[i + 1] |= dp[i - 2];
            }
        }
        return dp[n];
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << boolalpha << Solution().validPartition(nums);
    return 0;
}