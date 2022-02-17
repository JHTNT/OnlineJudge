#include <cstdio>
#include <cstring>
using namespace std;

int gcd(int a, int b) {
    // 輾轉相除直到其中一個為 0，另一個值就是最大公因數
    while ((a %= b) && (b %= a)) {}
    return a + b;
}

int main() {
    int N, P = 1;
    char s1[35], s2[35];
    scanf("%d\n", &N);
    while (N--) {
        int n1 = 0, n2 = 0;
        fgets(s1, 35, stdin);
        fgets(s2, 35, stdin);
        // 將二進位轉為十進位
        for (int i = 0; i < strlen(s1) -1; i++) {
            n1 *= 2;
            n1 += s1[i] - '0';
        }
        for (int i = 0; i < strlen(s2) -1; i++) {
            n2 *= 2;
            n2 += s2[i] - '0';
        }
        // 最大公因數必須大於 1
        if (gcd(n1, n2) > 1) {
            printf("Pair #%d: All you need is love!\n", P++);
        } else {
            printf("Pair #%d: Love is not all you need!\n", P++);
        }
    }
    return 0;
}