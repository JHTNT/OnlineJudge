#include <bits/stdc++.h>
using namespace std;

// ===== Solution 1 ===== (26 ms)

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> time(n, vector<int>(m, 0));
    vector<int> total(k, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> time[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        unordered_set<int> days;
        for (int j = 0; j < n; j++) {
            days.insert(time[j][i]);
        }
        for (int d : days) total[d - 1]++;
    }
    for (int i = 0; i < k; i++) cout << total[i] << " ";
    return 0;
}

// ===== Solution 2 ===== (33 ms)

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int n, m, k;
//     cin >> n >> m >> k;
//     vector<vector<int>> time(m, vector<int>(k + 1, 0));

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             int x;
//             cin >> x;
//             time[j][x] = 1;
//         }
//     }

//     for (int i = 1; i <= k; i++) {
//         int cnt = 0;
//         for (int j = 0; j < m; j++) {
//             cnt += time[j][i];
//         }
//         cout << cnt << " ";
//     }
//     return 0;
// }
