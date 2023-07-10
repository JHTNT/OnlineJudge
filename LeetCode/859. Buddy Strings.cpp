#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;
        if (s == goal) {
            vector<int> alphabet(26, 0);
            for (char i : s) {
                if (++alphabet[i - 'a'] == 2) return true;
            }
            return false;
        }

        int cnt = 0;
        char a, b;
        bool valid = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i]) {
                if (cnt == 0) {
                    a = s[i], b = goal[i];
                    cnt++;
                } else if (cnt == 1) {
                    if (a == goal[i] && b == s[i]) valid = true;
                    cnt++;
                } else {
                    return false;
                }
            }
        }
        return valid;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, goal;
    cin >> s >> goal;
    cout << boolalpha << Solution().buddyStrings(s, goal);
    return 0;
}
