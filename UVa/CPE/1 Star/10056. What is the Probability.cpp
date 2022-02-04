/*
p 為單次成功機率，設 q = 1 - p，共有 R 回合、n 個人
第 1 輪:
    第 1 人獲勝機率: p
    第 2 人獲勝機率: q * p
    第 3 人獲勝機率: (q ^ 2) * p
    第 k 人獲勝機率: (q ^ (k - 1)) * p
第 2 輪:
    第 1 人獲勝機率: (q ^ n) * p
    第 2 人獲勝機率: (q ^ n) * q * p
    第 3 人獲勝機率: (q ^ n) * (q ^ 2) * p
    第 k 人獲勝機率: (q ^ n) * (q ^ (k - 1)) * p
第 R 輪:
    第 1 人獲勝機率: (q ^ n(R - 1)) * p
    第 2 人獲勝機率: (q ^ n(R - 1)) * q
    第 3 人獲勝機率: (q ^ n(R - 1)) * (q ^ 2) * p
    第 k 人獲勝機率: (q ^ n(R - 1)) * (q ^ (k - 1)) * p

第 k 人在第 R 輪的獲勝機率即為答案，R 趨近於無限可用無窮等比級數公式求出
設首項 (q ^ (k - 1)) * p = a，公比 q * n = r
第 R 輪的機率和為 a / (1 - r)
*/
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int S, N, x;
    double p;
    scanf("%d", &S);
    while (S--) {
        scanf("%d %lf %d", &N, &p, &x);
        if (p == 0) {
            printf("0.0000\n");
            continue;
        }
        double a = pow((1 - p), x - 1) * p;
        double r = pow((1 - p), N);
        printf("%.4lf\n", a / (1 - r));
    }
    return 0;
}