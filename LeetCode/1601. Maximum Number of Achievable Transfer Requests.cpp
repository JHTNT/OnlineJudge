#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int ans = 0;
    int maximumRequests(int n, vector<vector<int>> &requests) {
        vector<int> transfer(n, 0);
        dfs(0, transfer, requests, n, 0);
        return ans;
    }

   private:
    void dfs(int i, vector<int> &transfer, vector<vector<int>> &requests, int n, int processed) {
        if (i == requests.size()) {
            if (all_of(transfer.begin(), transfer.end(), [](int i) { return i == 0; })) {
                ans = max(ans, processed);
            }
            return;
        }

        transfer[requests[i][0]]--, transfer[requests[i][1]]++;
        dfs(i + 1, transfer, requests, n, processed + 1);
        transfer[requests[i][0]]++, transfer[requests[i][1]]--;
        dfs(i + 1, transfer, requests, n, processed);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    cin >> n;
    vector<vector<int>> requests;
    while (cin >> a) {
        cin >> b;
        requests.push_back(vector<int>{a, b});
    }
    cout << Solution().maximumRequests(n, requests);
    return 0;
}
