#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;

        for (int i : coins) {
            for (int j = i; j <= amount; j++) {
                dp[j] += dp[j - i];
            }
        }
        return dp[amount];
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    cout << Solution().change(amount, coins);
    return 0;
}