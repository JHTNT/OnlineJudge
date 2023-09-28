// Q-3-12. 完美彩帶 (APCS201906)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n, tape[200005], cnt[200005] = {0};
    map<int, int> colorId;

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> tape[i];
        colorId[tape[i]] = 0;
    }

    int nColor = 0;
    for (auto &e : colorId) e.second = nColor++;

    int left = 0, right = 0, wColor = 0, ans = 0;
    while (right < n) {
        int color = colorId[tape[right]];
        if (++cnt[color] == 1) wColor++;
        right++;

        while (cnt[color] != 1) {
            if (--cnt[colorId[tape[left]]] == 0) wColor--;
            left++;
        }

        if (wColor == m) {
            cnt[colorId[tape[left]]]--;
            left++, wColor--, ans++;
        }
    }
    cout << ans;
    return 0;
}