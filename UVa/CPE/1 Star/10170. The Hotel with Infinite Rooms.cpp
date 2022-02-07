#include <cstdio>
using namespace std;

int main() {
    long long S, D;
    while (scanf("%d %lld", &S, &D) != EOF) {
        while (D > 0) D -= S++;
        printf("%lld\n", S - 1);
    }
    return 0;
}
/*
也可以直接用公式解
S + (S + 1) + (S + 2) + ... + n ≤ D
求出大於等於 n 的最小整數即為答案
*/