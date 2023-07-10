#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int distributeCookies(vector<int> &cookies, int k) {
        vector<int> distribution(k, 0);
        return dfs(0, distribution, cookies, k, k);
    }

   private:
    int dfs(int i, vector<int> &distribution, vector<int> &cookies, int k, int noCookie) {
        if (cookies.size() - i < noCookie) return INT_MAX;

        if (i == cookies.size()) return *max_element(distribution.begin(), distribution.end());

        int answer = INT_MAX;
        for (int j = 0; j < k; j++) {
            if (distribution[j] == 0) noCookie--;
            distribution[j] += cookies[i];
            answer = min(answer, dfs(i + 1, distribution, cookies, k, noCookie));
            distribution[j] -= cookies[i];
            if (distribution[j] == 0) noCookie++;
        }
        return answer;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, tmp;
    vector<int> cookies;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        cookies.push_back(tmp);
    }
    cout << Solution().distributeCookies(cookies, k);
    return 0;
}
