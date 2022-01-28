#include <stdio.h>
using namespace std;

/* 迴圈
int main() {
    int n, ans = 0;
    long long P = 10009, A[26];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &A[i]);
    }
    for (int s = 1; s < (1 << n); s++) {        // n 個元素的子集合有 2^n 個，再減去空集合
        long long product = 1;
        for (int j = 0; j < n; j++) {       // 若第 j 個 bit 是 1 表示該元素存在
            if (s & (1 << j)) {         // 利用 AND 運算
                product = (product * A[j]) % P;         // 題目只求餘數
            }
        }
        if (product == 1) ans++;
    }
    printf("%d\n", ans);
}
*/

// 遞迴
int n, ans = 0;
long long P = 10009, A[26];

void recursion(int i, int product) {
    if (i == n) {       // 終止條件
        if (product == 1) ans++;
        return;
    }
    recursion(i + 1, (product * A[i]) % P);         // 包含 A[i]
    recursion(i + 1, product);          // 不包含 A[i]
    return;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &A[i]);
    }
    ans = 0;
    recursion(0, 1);        // index = 0; product = 1
    printf("%d", ans - 1);          // 扣掉 1 排除空集合
    return 0;
}