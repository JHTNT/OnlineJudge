#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        int ans = 0, k = INT_MIN;
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });

        for (vector<int> interval : intervals) {
            if (interval[0] >= k)  // start of this interval is greater than k
                k = interval[1];   // k equal to the end of this interval
            else
                ans++;  // skip this interval
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}