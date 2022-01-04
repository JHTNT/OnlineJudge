#include <stdio.h>
#include <math.h>
using namespace std;

int tuple[16];

void next_cycle(int n) {
    int tmp = tuple[0];
    for (int i = 0; i < n - 1; i++) {
        tuple[i] = abs(tuple[i] - tuple[i + 1]);
    }
    tuple[n - 1] = abs(tuple[n - 1] - tmp);
}

bool zero(int n) {
    for (int i = 0; i < n; i++) {
        if (tuple[i]) return false;
    }
    return true;
}

int main() {
    int T, n;
    bool is_zero;
    scanf("%d", &T);
    while (T--) {
        is_zero = false;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &tuple[i]);
        }
        for (int i = 0; i < 1000; i++) {
            if (zero(n)) {      // 若整個陣列為 0 就 break 並輸出答案
                is_zero = true;
                break;
            }
            next_cycle(n);          // 產生下一次的陣列
        }
        if (is_zero) {
            printf("ZERO\n");
        } else {
            printf("LOOP\n");
        }
    }
}
