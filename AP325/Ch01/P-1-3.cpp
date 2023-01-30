// P-1-3. 棍子中點切割
#include <bits/stdc++.h>
using namespace std;

long long p[50005];

long long cut(int left, int right) {
    if (right - left <= 1) return 0;
    int m = left;
    long long k = (p[left] + p[right]) / 2;
    for (int jump = (right - left) / 2; jump > 0; jump /= 2) {
        while (m + jump < right && p[m + jump] < k)
            m += jump;
    }
    if (p[m] - p[left] < p[right] - p[m + 1])
        m++;
    return p[right] - p[left] + cut(left, m) + cut(m, right);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, L;
    cin >> n >> L;

    p[0] = 0, p[n + 1] = L;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    cout << cut(0, n + 1);
    return 0;
}