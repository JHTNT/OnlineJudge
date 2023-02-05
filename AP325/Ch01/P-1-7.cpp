// P-1-7. 子集合乘積
#include <bits/stdc++.h>
using namespace std;

/* 迴圈 (1.869 s)
int main() {
    int n, ans = 0;
    long long P = 10009, nums[26];

    cin >> n;
    for (int i = 0; i < n; i++) cin >> nums[i];
    for (int i = 1; i < (1 << n); i++) {
        long long prod = 1;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j))
                prod = prod * nums[j] % P;
        }
        if (prod == 1) ans++;
    }
    cout << ans;
    return 0;
}
*/

// 遞迴 (0.096 s)
int n, ans = 0;
long long P = 10009, nums[26];

void rec(int i, int prod) {
    if (i >= n) {
        if (prod == 1) ans++;
        return;
    }
    rec(i + 1, (prod * nums[i]) % P);
    rec(i + 1, prod);
    return;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> nums[i];
    rec(0, 1);
    cout << ans;
    return 0;
}