#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minSpeedOnTime(vector<int> &dist, double hour) {
        if (dist.size() - 1 >= hour) return -1;
        int left = 1, right = 1e7;

        while (left <= right) {
            int mid = (left + right) / 2;  // mid stands for speed
            double time = 0;

            for (int d : dist) {
                time = ceil(time);
                time += (double) d / mid;
            }

            if (time <= hour)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    double hour;
    cin >> n >> hour;
    vector<int> dist(n);
    for (int i = 0; i < n; i++) cin >> dist[i];
    cout << Solution().minSpeedOnTime(dist, hour);
    return 0;
}