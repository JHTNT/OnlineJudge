// Q-2-7. 互補團隊 (APCS201906)
#include <bits/stdc++.h>
using namespace std;

int a[50005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n, cnt = 0;
    string s;
    cin >> m >> n;
    int k = (1 << m) - 1;  // bits 0 ~ (m - 1) are 1
    for (int i = 0; i < n; i++) {
        cin >> s;
        int team = 0, len = s.size();
        for (int j = 0; j < len; j++)
            team |= 1 << (s[j] - 'A');
        a[i] = team;
    }
    sort(a, a + n);

    int i = 0, j = n - 1;
    for (; i < n; i++) {
        while (j > i && a[j] > k - a[i]) j--;
        if (a[i] + a[j] == k) cnt++;
    }
    cout << cnt;
    return 0;
}