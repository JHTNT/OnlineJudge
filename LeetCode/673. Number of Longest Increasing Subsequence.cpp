#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> length(n, 1), cnt(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (length[j] + 1 > length[i]) {
                        length[i] = length[j] + 1;
                        cnt[i] = 0;
                    }

                    if (length[j] + 1 == length[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
        }

        int maxLength = *max_element(length.begin(), length.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (length[i] == maxLength) {
                ans += cnt[i];
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << Solution().findNumberOfLIS(nums);
    return 0;
}
