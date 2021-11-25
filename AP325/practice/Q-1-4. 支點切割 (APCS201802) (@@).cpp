// 參考 https://yuihuang.com/zj-f638/
#include <stdio.h>
#include <cmath>
#define MAXN 50005
using namespace std;

int p[MAXN];
long long lps[MAXN], rps[MAXN];         // lps = left prefix sum
int k;          // 將最大遞迴層數設為全域變數

// 計算切割費用總和
int cut(int left, int right, int level) {       // level 為遞迴層數
    if (level == k) return 0;           // 達到遞迴層數上限
    if (right - left < 2) return 0;         // 少於三個無法再切割

    /* 計算前綴和
    rps 從左到右
    delta | 0 | p1 | p1 + p2  | p1 + p2 + p3   | p1 + p2 + p3 + p4    |
    lps   | 0 | p1 | 2p1 + p2 | 3p1 + 2p2 + p3 | 4p1 + 3p2 + 2p3 + p4 |
    rps 同理，改為由右往左
    delta | p1 + p2 + p3 + p4    | p2 + p3 + p4   | p3 + p4  | p4 | 0 |
    rps   | p1 + 2p2 + 3p3 + 4p4 | p2 + 2p3 + 3p4 | p3 + 2p4 | p4 | 0 |
    */
    long long delta = 0;
    lps[left] = 0;
    for (int i = left + 1; i <= right; i++) {
        delta += p[i - 1];
        lps[i] = lps[i - 1] + delta;
    }
    delta = 0;
    rps[right] = 0;
    for (int i = right - 1; i >= left; i--) {
        delta += p[i + 1];
        rps[i] = rps[i + 1] + delta;
    }

    // 找除了兩端點外的最佳切點
    long long mn = 2e18;        // 2^31 * 2^31
    int index = 0;
    for (int i = left + 1; i <= right - 1; i++) {
        long long cost = abs(rps[i] - lps[i]);          // cost 為左右各點加權總合的"差"
        if (cost < mn) {
            mn = cost;
            index = i;
        }
    }
    return p[index] + cut(left, index - 1, level + 1) + cut(index + 1, right, level + 1);
}

int main() {
    int n;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    printf("%d", cut(1, n, 0));
    return 0;
}