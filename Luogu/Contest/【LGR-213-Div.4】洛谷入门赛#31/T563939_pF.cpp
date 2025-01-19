#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> p_sum(m, 0);
    vector<vector<int>> k(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> k[i][j];
            p_sum[j] += k[i][j];
        }
    }

    int max_col = 0;
    for (int i = 1; i < m; i++) {
        if (p_sum[i] >= p_sum[max_col]) max_col = i;
    }

    int max_k = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (k[i][max_col] > max_k) {
            max_k = k[i][max_col];
            cnt = 1;
        } else if (k[i][max_col] == max_k) {
            cnt++;
        }
    }
    cout << max_k << " " << cnt;
    return 0;
}
