#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        string phone_button[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backtrack("", digits, phone_button);
        return ans;
    }

   private:
    vector<string> ans;
    void backtrack(string combination, string remaining_digits, string phone_button[]) {
        if (remaining_digits.empty()) {
            ans.push_back(combination);
        } else {
            for (char letter : phone_button[remaining_digits[0] - '2']) {
                backtrack(combination + letter, remaining_digits.substr(1), phone_button);
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string digits;
    cin >> digits;
    vector<string> ans = Solution().letterCombinations(digits);
    for (string s : ans) cout << s << "\n";
    return 0;
}