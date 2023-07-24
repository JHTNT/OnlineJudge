#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        deque<int> dq;
        for (int asteroid : asteroids) {
            bool destroyed = false;
            while (!dq.empty() && (asteroid < 0 && dq.back() > 0)) {
                if (abs(asteroid) > abs(dq.back())) {
                    dq.pop_back();
                    continue;
                } else {
                    if (abs(asteroid) == abs(dq.back())) dq.pop_back();
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) dq.push_back(asteroid);
        }

        vector<int> ans;
        for (int i : dq) ans.push_back(i);
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> asteroids(n);
    for (int i = 0; i < n; i++) cin >> asteroids[i];
    for (int i : Solution().asteroidCollision(asteroids)) cout << i << " ";
    return 0;
}