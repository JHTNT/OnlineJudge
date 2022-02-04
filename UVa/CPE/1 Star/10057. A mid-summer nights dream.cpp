#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n, mid1, mid2;
    while (scanf("%d", &n) != EOF) {
        int x[n], ans = 0;
        for (int i = 0; i < n; i++) scanf("%d", &x[i]);
        sort(x, x + n);
        // 若 n 為奇數則 mid1 會等於 mid2
        mid1 = x[(n - 1) / 2];
        mid2 = x[n / 2];
        // 計算 |Xi - A| 為最小值的數量
        for (int i = 0; i < n; i++) {
            if (x[i] == mid1 || x[i] == mid2) ans++;
        }
        // 第三個數字表示有多少個算式最小值
        printf("%d %d %d\n", mid1, ans, mid2 - mid1 + 1);
    }
    return 0;
}