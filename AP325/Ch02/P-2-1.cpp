// P-2-1. 不同的數—排序
#include <bits/stdc++.h>
using namespace std;

int distinct(int from[], int to[], int n) {
    if (n == 0) return 0;
    vector<int> v(from, from + n);
    sort(v.begin(), v.end());
    to[0] = v[0];
    int cnt = 1;
    for (int i = 1; i < n; i++)
        if (v[i] != v[i - 1])
            to[cnt++] = v[i];
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a[100005], b[100005], n, k;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    k = distinct(a, b, n);
    cout << k << "\n";
    for (int i = 0; i < k; i++)
        cout << b[i] << " ";
    return 0;
}