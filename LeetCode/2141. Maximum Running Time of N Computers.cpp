#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long extraPower = 0;
        sort(batteries.begin(), batteries.end());
        for (int i = 0; i < batteries.size() - n; i++) extraPower += batteries[i];

        vector<int> selected {batteries.end() - n, batteries.end()};
        for (int i = 0; i < n - 1; i++) {
            if (extraPower < (long long) (i + 1) * (selected[i + 1] - selected[i]))
                return selected[i] + extraPower / (i + 1);
            extraPower -= (long long) (i + 1) * (selected[i + 1] - selected[i]);
        }

        return selected[n - 1] + extraPower / n;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> batteries(k);
    for (int i = 0; i < k; i++) cin >> batteries[i];
    cout << Solution().maxRunTime(n, batteries);
    return 0;
}