// Q-1-10. 最多得分的皇后
#include <bits/stdc++.h>
using namespace std;

int scores[14][14];


int nq(int n, int k, int p[]) {
    if (k == n) {
        int total = 0;
        for (int i = 0; i < n; i++)
            if (p[i] != -1)
                total += scores[p[i]][i];
        return total;
    }
    int res = 0;
    bool valid[n];
    for (int i = 0; i < n; i++) valid[i] = true;
    for (int j = 0; j < k; j++) {
        if (p[j] == -1) continue;
        valid[p[j]] = false;
        int i = k - j + p[j];
        if (i < n) valid[i] = false;
        i = p[j] - (k - j);
        if (i >= 0) valid[i] = false;
    }
    for (int i = 0; i < n; i++) {
        if (valid[i]) {
            p[k] = i;
            res = max(res, nq(n, k + 1, p));
        }
    }
    p[k] = -1;
    res = max(res, nq(n, k + 1, p));
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> scores[i][j];
    cout << nq(n, 0, p);
    return 0;
}