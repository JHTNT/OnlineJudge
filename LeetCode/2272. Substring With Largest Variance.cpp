#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int largestVariance(string s) {
        int ans = 0;
        vector<int> counter(26, 0);
        unordered_set<int> alphabet(s.begin(), s.end());
        for (char c : s) {
            counter[c - 'a']++;
        }

        for (char major : alphabet) {
            for (char minor : alphabet) {
                if (major == minor) continue;
                int majorCnt = 0, minorCnt = 0, restMinor = counter[minor - 'a'];
                for (char c : s) {
                    if (c == major) {
                        majorCnt++;
                    } else if (c == minor) {
                        minorCnt++;
                        restMinor--;
                    }

                    if (minorCnt > 0) ans = max(ans, majorCnt - minorCnt);

                    if (majorCnt < minorCnt && restMinor > 0) {
                        majorCnt = 0;
                        minorCnt = 0;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    cout << Solution().largestVariance(s);
    return 0;
}