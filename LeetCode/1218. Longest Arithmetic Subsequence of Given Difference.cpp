#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans = 1;
        unordered_map<int, int> length;

        for (int i : arr) {
            // length of subsequence end with i
            int prev = length.count(i - difference) ? length[i - difference] : 0;
            length[i] = prev + 1;
            ans = max(ans, length[i]);
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}