#include <bits/stdc++.h>
using namespace std;

// ===== Solution 1 ===== (71 ms)

// map<tuple<long long, long long, long long>, long long> record;

// long long w(long long a, long long b, long long c) {
//     if (a <= 0 || b <= 0 || c <= 0) return 1;

//     auto nums = make_tuple(a, b, c);
//     if (record.count(nums)) {
//         return record[nums];
//     } else {
//         long long res;
//         if (a > 20 || b > 20 || c > 20)
//             res = w(20, 20, 20);
//         else if (a < b && b < c)
//             res = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
//         else
//             res = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c -
//             1);
//         record.insert({nums, res});
//         return res;
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     long long a, b, c;
//     while (cin >> a >> b >> c) {
//         if (a == -1 && b == -1 && c == -1) break;
//         cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
//     }
//     return 0;
// }

// ===== Solution 2 ===== (60 ms)

long long record[25][25][25];

long long w(long long a, long long b, long long c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);

    if (record[a][b][c]) return record[a][b][c];
    if (a < b && b < c) {
        if (!record[a][b][c - 1]) record[a][b][c - 1] = w(a, b, c - 1);
        if (!record[a][b - 1][c - 1]) record[a][b - 1][c - 1] = w(a, b - 1, c - 1);
        if (!record[a][b - 1][c]) record[a][b - 1][c] = w(a, b - 1, c);
        record[a][b][c] = record[a][b][c - 1] + record[a][b - 1][c - 1] - record[a][b - 1][c];
    } else {
        if (!record[a - 1][b][c]) record[a - 1][b][c] = w(a - 1, b, c);
        if (!record[a - 1][b - 1][c]) record[a - 1][b - 1][c] = w(a - 1, b - 1, c);
        if (!record[a - 1][b][c - 1]) record[a - 1][b][c - 1] = w(a - 1, b, c - 1);
        if (!record[a - 1][b - 1][c - 1]) record[a - 1][b - 1][c - 1] = w(a - 1, b - 1, c - 1);
        record[a][b][c] = record[a - 1][b][c] + record[a - 1][b - 1][c] + record[a - 1][b][c - 1] -
                          record[a - 1][b - 1][c - 1];
    }
    return record[a][b][c];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a, b, c;
    while (cin >> a >> b >> c) {
        if (a == -1 && b == -1 && c == -1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
    }
    return 0;
}
