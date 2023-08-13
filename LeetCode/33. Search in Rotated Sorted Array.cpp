#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int search(std::vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == target) return mid;

            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return -1;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << Solution().search(nums, target);
    return 0;
}