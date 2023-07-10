// P-3-7. 正整數序列之最接近的區間和
#include <bits/stdc++.h>
using namespace std;

int a[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    int left = 0, right = 0, sum = 0, cnt = 0, ans = 0;
    for (; right < n; right++) {
        sum += a[right];
        while (sum > k) sum -= a[left++];
        if (sum > ans) {
            ans = sum;
            cnt = 1;
        } else if (sum == ans) {
            cnt++;
        }
    }
    cout << ans << "\n" << cnt;
    return 0;
}
