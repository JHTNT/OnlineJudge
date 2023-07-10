#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long putMarbles(vector<int> &weights, int k) {
        priority_queue<int> q1;                             // large to small
        priority_queue<int, vector<int>, greater<int>> q2;  // small to large

        for (int i = 0; i < weights.size() - 1; i++) {
            q1.push(weights[i] + weights[i + 1]);
            q2.push(weights[i] + weights[i + 1]);

            if (q1.size() >= k) q1.pop(), q2.pop();
        }

        long long max_score = 0, min_score = 0;
        for (int i = 0; i < q1.size(); i++) {
            min_score += q1.top(), max_score += q2.top();
            q1.pop(), q2.pop();
        }
        return max_score - min_score;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, tmp;
    vector<int> weights;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        weights.push_back(tmp);
    }
    cout << Solution().putMarbles(weights, k);
    return 0;
}
