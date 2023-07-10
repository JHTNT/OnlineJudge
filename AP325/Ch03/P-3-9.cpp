// P-3-9. 最多色彩帶
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, L, ans = 0, nColor = 0;
    cin >> n >> L;
    int color[n], cnt[n] = {0};
    for (int i = 0; i < n; i++) cin >> color[i];

    for (int i = 0; i < L; i++) {
        cnt[color[i]]++;
        if (cnt[color[i]] == 1) nColor++;
    }
    ans = nColor;
    for (int left = 0, i = L; i < n; left++, i++) {
        cnt[color[i]]++;
        if (cnt[color[i]] == 1) nColor++;
        cnt[color[left]]--;
        if (cnt[color[left]] == 0) nColor--;
        ans = max(ans, nColor);
    }
    cout << ans;
    return 0;
}