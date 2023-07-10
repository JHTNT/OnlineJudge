#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int singleNumber(vector<int> &nums) {
        int one = 0, two = 0;
        for (int num : nums) {
            one = (one ^ num) & ~two;
            two = (two ^ num) & ~one;
        }
        return one;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tmp;
    vector<int> nums;
    while (cin >> tmp) nums.push_back(tmp);
    cout << Solution().singleNumber(nums);
    return 0;
}
