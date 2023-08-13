#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    double myPow(double x, int n) {
        long long y = n;
        double t = 1;
        if (y < 0) {
            x = -1.0 / x;
            y = -y;
        }

        while (y > 0) {
            if (y & 1) t *= x;
            x *= x;
            y >>= 1;
        }
        return t;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double x;
    int n;
    cin >> x >> n;
    cout << Solution().myPow(x, n); 
    return 0;
}