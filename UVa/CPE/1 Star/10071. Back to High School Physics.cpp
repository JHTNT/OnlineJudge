#include <cstdio>
using namespace std;

int main() {
    int v, t;
    // 2t 時速度為 2v，位移為 1/2 * 2v * 2t = 2vt
    while (scanf("%d %d", &v, &t) != EOF) {
        printf("%d\n", 2 * v * t);
    }
    return 0;
}