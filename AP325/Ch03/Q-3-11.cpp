// Q-3-11. 最長的相異色彩帶
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, tape[200005], cnt[200005] = {0};

    cin >> n;
    int left = 0, right = 0, ans = 0;
    for (; right < n; right++) {
        cin >> tape[right];
        if (++cnt[tape[right]] != 1) {
            ans = max(ans, right - left);
            while (cnt[tape[right]] != 1) {
                cnt[tape[left]]--;
                left++;
            }
        }
    }
    ans = max(ans, right - left + 1);
    cout << ans;
    return 0;
}
