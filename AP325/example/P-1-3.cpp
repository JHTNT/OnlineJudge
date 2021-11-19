#include <stdio.h>
using namespace std;

long long p[50001];       // 最多 50000 個切割點，輸入後不做更改

long long cut(int left, int right) {        // left 跟 right 是切割點的索引值
    if (right - left <= 1) return 0;        // 若左右相同或無法再切割就回傳 0
    int m = left;
    long long k = (p[left] + p[right]) / 2;         // 此段木棍中點
    for (int jump = (right - left) / 2; jump > 0; jump >>= 1) {
        while (m + jump < right && p[m + jump] < k) {
            // 確保 m + jump 不超過右界且所代表的切割點小於中點
            m += jump;
        }
    }
    if (p[m] - p[left] < p[right] - p[m + 1]) m++;          // 如果 m + 1 更接近中點就選它
    return (p[right] - p[left]) + cut(left, m) + cut(m, right);         // 成本為該段長度
}

int main() {
    freopen("test.in", "r", stdin);
    freopen("test.out","w", stdout);
    int n, l;
    scanf("%d %d", &n, &l);
    p[0] = 0;
    p[n + 1] = l;       // 將棍子起點與終點初始化到切割點陣列
    for (int i = 1; i <= n; i++) scanf("%lld", &p[i]);
    printf("%lld\n", cut(0, n + 1));
    return 0;
}