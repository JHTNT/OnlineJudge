#include <bits/stdc++.h>
using namespace std;

// ===== Solution 1 ===== (60 ms)

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int n, x, cnt = 0;
//     cin >> n >> x;
//     for (int i = 1; i <= n; i++) {
//         int k = i;
//         while (k > 0) {
//             if (k % 10 == x) cnt++;
//             k /= 10;
//         }
//     }
//     cout << cnt << "\n";
//     return 0;
// }

// ===== Solution 2 ===== (31 ms)

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x, cnt = 0, m = 1;
    cin >> n >> x;
    while (m <= n) {
        // m = 1 => 個位數，m = 10 => 十位數...
        // Ex. n = 1234, m = 10
        //     left = 12, mid = 3, right = 4
        int left = n / (m * 10), mid = n / m % 10, right = n % m;
        if (x > 0) {
            if (mid > x) {
                cnt += (left + 1) * m;  // left = 0 的情況也要算
            } else if (mid == x) {
                cnt += left * m + right + 1;
            } else if (mid < x) {
                cnt += left * m;
            }
        } else {
            // 若 x 為 0 則 left 不能是 0
            if (mid > 0) {
                cnt += left * m;
            } else {
                cnt += (left - 1) * m + right + 1;
            }
        }
        m *= 10;
    }
    cout << cnt << "\n";
    return 0;
}
