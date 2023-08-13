#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimizeMax(vector<int> &nums, int p) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front();

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (countValidPairs(nums, mid) >= p)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

   private:
    int countValidPairs(vector<int> &nums, int threshold) {
        int count = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] - nums[i] <= threshold) {
                count++;
                i++;
            }
        }
        return count;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, p;
    cin >> n >> p;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[n];
    cout << Solution().minimizeMax(nums, p);
    return 0;
}