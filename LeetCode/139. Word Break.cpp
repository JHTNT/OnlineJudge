#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        this->memo = vector(s.length(), -1);
        this->wordDict = wordDict;
        this->s = s;
        return dp(s.length() - 1);
    }

   private:
    vector<int> memo;
    vector<string> wordDict;
    string s;
    bool dp(int i) {
        if (i < 0) return true;

        if (memo[i] != -1) return memo[i] == 1;

        for (string word : wordDict) {
            int currSize = word.length();
            // out of bounds
            if (i - currSize + 1 < 0) {
                continue;
            }

            if (s.substr(i - currSize + 1, currSize) == word && dp(i - currSize)) {
                memo[i] = 1;
                return true;
            }
        }

        memo[i] = 0;
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n;
    vector<string> wordDict(n);
    for (int i = 0; i < n; i++) cin >> wordDict[i];
    cout << boolalpha << Solution().wordBreak(s, wordDict);
    return 0;
}