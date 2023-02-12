// P-2-6. Two-Number problem
#include <bits/stdc++.h>
using namespace std;

int a[100005], b[100005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n, k, cnt = 0;
    cin >> m >> n >> k;
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a, a + m);
    sort(b, b + n);

    int i = 0, j = n - 1;
    for (; i < m; i++) {
        while (j > 0 && b[j] > k - a[i]) j--;
        if (a[i] + b[j] == k) cnt++;
    }
    cout << cnt;
    return 0;
}