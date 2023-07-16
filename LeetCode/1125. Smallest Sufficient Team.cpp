#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = people.size(), m = req_skills.size();
        unordered_map<string, int> skillId;
        for (int i = 0; i < m; i++) skillId[req_skills[i]] = i;

        vector<int> skillsMaskOfPerson(n);
        for (int i = 0; i < n; i++) {
            for (string skill : people[i]) {
                // skills of each person in bitmask
                skillsMaskOfPerson[i] |= 1 << skillId[skill];
            }
        }

        vector<long long> dp(1 << m, (1LL << m) - 1);
        dp[0] = 0;

        for (int skillsMask = 1; skillsMask < (1 << m); skillsMask++) {
            for (int i = 0; i < n; i++) {
                // get skill mask without ith person's skills
                int smallerSkillMask = skillsMask & ~skillsMaskOfPerson[i];
                if (smallerSkillMask != skillsMask) {
                    long long peopleMask = dp[smallerSkillMask] | (1LL << i);  // add ith people
                    if (__builtin_popcountll(peopleMask) < __builtin_popcountll(dp[skillsMask])) {
                        dp[skillsMask] = peopleMask;
                    }
                }
            }
        }

        long long answerMask = dp[(1 << m) - 1];
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if ((answerMask >> i) & 1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}