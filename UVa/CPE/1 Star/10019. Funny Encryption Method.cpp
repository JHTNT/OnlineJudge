#include <cstdio>
using namespace std;

int main() {
    int T, n, x1, x2, b1, b2, hex;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        x1 = n, b1 = 0;
        while (x1) {
            b1 += x1 & 1;       // 最右位元是否為 1
            x1 >>= 1;        // 向右偏移 1 位元，相當於除以 2
        }
        x2 = 0, b2 = 0, hex = 1;
        while (n) {         // 十六進位轉十進位
            x2 += (n % 10) * hex;
            n /= 10;
            hex *= 16;
        }
        while (x2) {
            b2 += x2 & 1;
            x2 >>= 1;
        }
        printf("%d %d\n", b1, b2);
    }
    return 0;
}