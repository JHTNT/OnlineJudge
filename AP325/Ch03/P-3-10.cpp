// P-3-10. 全彩彩帶 (需離散化或字典) (@@)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, tape[200005], cnt[200005] = {0};
    map<int, int> colorId;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tape[i];
        colorId[tape[i]] = 0;
    }

    int nColor = 0;  // num of color
    for (auto &e : colorId) e.second = nColor++;

    // wColor = num of color in window
    int left = 0, right = 0, wColor = 0, ans = n;
    while (right < n) {
        int color = colorId[tape[right]];
        if (++cnt[color] == 1) wColor++;
        right++;

        while (true) {
            color = colorId[tape[left]];
            if (cnt[color] == 1) break;
            cnt[color]--;
            left++;
        }

        if (wColor == nColor) ans = min(ans, right - left);
    }
    cout << ans;
    return 0;
}