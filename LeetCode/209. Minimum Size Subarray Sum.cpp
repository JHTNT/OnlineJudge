#include <bits/stdc++.h>
using namespace std;

// Sliding window: O(n)
class Solution {
   public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int ans = INT_MAX, left = 0, right = 0, sum = 0;
        for (int num : nums) {
            sum += num;
            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

// Prefix sum + binary search: O(nlogn)
class Solution {
   public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int n = nums.size(), ans = INT_MAX;
        vector<int> sums(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];  // prefix sum
        }
        for (int i = n; i >= 0 && sums[i] >= s; i--) {
            int j = upper_bound(sums.begin(), sums.end(), sums[i] - s) - sums.begin();
            ans = min(ans, i - j + 1);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, target, tmp;
    vector<int> nums;
    cin >> n >> target;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        nums.push_back(tmp);
    }
    cout << Solution().minSubArrayLen(target, nums);
    return 0;
}