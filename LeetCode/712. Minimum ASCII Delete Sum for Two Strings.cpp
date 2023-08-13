#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimumDeleteSum(string s1, string s2) {
        if (s1.length() < s2.length()) {
            return minimumDeleteSum(s2, s1);
        }

        int m = s1.length(), n = s2.length();
        vector<int> currRow(n + 1);
        for (int j = 1; j <= n; j++) {
            currRow[j] = currRow[j - 1] + s2[j - 1];
        }

        for (int i = 1; i <= m; i++) {
            int diag = currRow[0];
            currRow[0] += s1[i - 1];

            for (int j = 1; j <= n; j++) {
                int answer;

                if (s1[i - 1] == s2[j - 1])
                    answer = diag;
                else
                    answer = min(s1[i - 1] + currRow[j], s2[j - 1] + currRow[j - 1]);

                diag = currRow[j];
                currRow[j] = answer;
            }
        }
        return currRow[n];
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2;
    cin >> s1, s2;
    cout << Solution().minimumDeleteSum(s1, s2);
    return 0;
}