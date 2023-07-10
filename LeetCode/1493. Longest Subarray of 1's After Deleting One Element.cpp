#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int longestSubarray(vector<int> &nums) {
        int ans = 0, prev = 0, curr = 0;
        for (int i : nums) {
            if (i == 0) {
                ans = max(ans, prev + curr);
                prev = curr, curr = 0;
            } else {
                curr++;
            }
        }
        ans = max(ans, prev + curr);
        if (curr == nums.size()) ans--;
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, tmp;
    vector<int> nums;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        nums.push_back(tmp);
    }
    cout << Solution().longestSubarray(nums);
    return 0;
}
