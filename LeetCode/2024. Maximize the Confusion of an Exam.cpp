#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans = k;
        unordered_map<char, int> cnt;
        for (int i = 0; i < k; i++) {
            cnt[answerKey[i]]++;
        }

        int left = 0;
        for (int right = k; right < answerKey.size(); right++) {
            cnt[answerKey[right]]++;
            while (min(cnt['T'], cnt['F']) > k) {
                cnt[answerKey[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k;
    string answerKey;
    cin >> k >> answerKey;
    cout << Solution().maxConsecutiveAnswers(answerKey, k);
    return 0;
}