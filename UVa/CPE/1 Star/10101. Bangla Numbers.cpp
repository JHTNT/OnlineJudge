#include <cstdio>
using namespace std;

void split(long long n) {
    if (n >= 10000000) {
        split(n / 10000000);        // 超過 10^7 用遞迴分割
        printf(" kuti");
        n %= 10000000;
    }
    if (n >= 100000) {
        printf(" %d lakh", n / 100000);
        n %= 100000;
    }
    if (n >= 1000) {
        printf(" %d hajar", n / 1000);
        n %= 1000;
    }
    if (n >= 100) {
        printf(" %d shata", n / 100);
        n %= 100;
    }
    if (n) printf(" %d", n);
}

int main() {
    int count = 1;
    long long n;
    while (scanf("%lld", &n) != EOF) {
        printf("%4d.", count++);
        if (n == 0) printf(" 0");
        else split(n);
        printf("\n");
    }
    return 0;
}