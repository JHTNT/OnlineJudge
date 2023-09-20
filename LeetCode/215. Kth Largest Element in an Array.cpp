#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap;
        for (int num : nums) {
            heap.push(-num);
            if (heap.size() > k) {
                heap.pop();
            }
        }
        return -heap.top();
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << Solution().findKthLargest(nums, k);
    return 0;
}