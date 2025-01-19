#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int r_len = (n + 1) / 2;
    int l_len = max(m - r_len, 0);
    int mid = (n - 1) / 2;
    vector<vector<bool>> fig(n, vector<bool>(m, false));

    for (int i = mid - (k - 1) / 2; i <= mid + (k - 1) / 2; i++) {

        for (int j = 0; j < l_len; j++) {
            fig[i][j] = true;
        }
    }

    int cnt = 0;
    for (int i = l_len; i < m; i++) {
        for (int j = cnt; j < n - cnt; j++) {
            fig[j][i] = true;
        }
        cnt++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (fig[i][j]) {
                cout << "#";
            } else {
                cout << ".";
            }
        }
        cout << "\n";
    }
    return 0;
}
