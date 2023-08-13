#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool search(std::vector<int>& nums, int target) {
        if (nums.empty()) return false;

        int n = nums.size();
        int start = 0, end = n - 1;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (nums[mid] == target) return true;

            // can't find the relative position of nums[mid] and target
            if (nums[start] == nums[mid]) {
                start++;
                continue;
            }

            // we have two parts of the array based on the rotation
            // check if nums[mid] and target in the different part
            if ((nums[mid] >= nums[start]) ^ (target >= nums[start])) {  // XOR
                if ((nums[mid] >= nums[start]))  // nums[mid] at first part, target at second part
                    start = mid + 1;
                else
                    end = mid - 1;
            } else {
                if (nums[mid] < target)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return false;
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