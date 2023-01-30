// Q-1-11. 刪除矩形邊界 — 遞迴 (APCS201910, subtask)
#include <bits/stdc++.h>
using namespace std;

int arr[13][13];

int cut(int left, int top, int right, int bottom, int cost) {
    if (left == right || top == bottom) return cost;
    int cnt, l, t, r, b;

    cnt = 0;
    for (int i = top; i <= bottom; i++)
        if (arr[i][left] == 0) cnt++;
    cnt = min(cnt, bottom - top + 1 - cnt);
    l = cut(left + 1, top, right, bottom, cost + cnt);

    cnt = 0;
    for (int i = left; i <= right; i++)
        if (arr[top][i] == 0) cnt++;
    cnt = min(cnt, right - left + 1 - cnt);
    t = cut(left, top + 1, right, bottom, cost + cnt);

    cnt = 0;
    for (int i = top; i <= bottom; i++)
        if (arr[i][right] == 0) cnt++;
    cnt = min(cnt, bottom - top + 1 - cnt);
    r = cut(left, top, right - 1, bottom, cost + cnt);

    cnt = 0;
    for (int i = left; i <= right; i++)
        if (arr[bottom][i] == 0) cnt++;
    cnt = min(cnt, right - left + 1 - cnt);
    b = cut(left, top, right, bottom - 1, cost + cnt);
    return min({l, t, r, b});
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    cout << cut(0, 0, n - 1, m - 1, 0);
    return 0;
}