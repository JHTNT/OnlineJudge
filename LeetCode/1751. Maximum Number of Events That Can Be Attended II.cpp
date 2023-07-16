#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());

        vector<vector<int>> dp(k + 1, vector<int>(events.size(), -1));
        return dfs(0, k, events, dp);
    }

   private:
    int binarySearch(int index, vector<vector<int>>& events, int val) {
        int low = index, high = events.size() - 1, nextIndex = -1;

        while (high >= low) {
            int mid = low + (high - low) / 2;
            if (events[mid][0] > val) {
                nextIndex = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return nextIndex;
    }

    int dfs(int index, int cnt, vector<vector<int>>& e, vector<vector<int>>& dp) {
        if (cnt == 0 || index >= e.size()) return 0;

        if (dp[cnt][index] != -1) return dp[cnt][index];

        int nextIndex = binarySearch(index + 1, e, e[index][1]);
        return dp[cnt][index] =
                   max(e[index][2] + dfs(nextIndex, cnt - 1, e, dp), dfs(index + 1, cnt, e, dp));
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int>> e{{1, 2, 4}, {3, 4, 3}, {2, 3, 1}};
    cout << Solution().maxValue(e, 2);
    return 0;
}