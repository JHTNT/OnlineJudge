// P-1-9. N-Queen 解的個數
#include <bits/stdc++.h>
using namespace std;

/* 迴圈 (2.156 s)
int nq(int n) {
    int p[12], total = 0;
    for (int i = 0; i < n; i++) p[i] = i;
    do {
        bool valid = true;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (abs(p[i] - p[j] == j - i)) {
                    valid = false;
                    break;
                }
        if (valid) total++;
    } while (next_permutation(p, p + n));
    return total;
}

int main() {
    for (int i = 1; i < 12; i++)
        cout << nq(i) << " ";
    return 0;
}
*/

// 遞迴 (0.01 s)
// k is current row, p[] are column indexes of previous rows
int nqr(int n, int k, int p[]) {
    if (k >= n) return 1;
    int total = 0;
    bool valid[n];
    for (int i = 0; i < n; i++) valid[i] = true;
    for (int j = 0; j < k; j++) {
        valid[p[j]] = false;
        int i = k - j + p[j];
        if (i < n) valid[i] = false;
        i = p[j] - (k - j);
        if (i >= 0) valid[i] = false;
    }
    for (int i = 0; i < n; i++) {
        if (valid[i]) {
            p[k] = i;
            total += nqr(n, k + 1, p);
        }
    }
    return total;
}

int main() {
    int p[12];
    for (int i = 1; i < 12; i++)
        cout << nqr(i, 0, p) << " ";
    return 0;
}