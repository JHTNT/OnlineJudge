#include <stdio.h>
using namespace std;

int n, P, A[26], ans;

void recursion(int index, int sum) {
    if (index >= n) {
        if (sum > ans && sum <= P) ans = sum;       // 總和不超過 P
        return;
    }
    recursion(index + 1, sum + A[index]);
    recursion(index + 1, sum);
    return;
}

int main() {
    scanf("%d %d", &n, &P);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    ans = 0;
    recursion(0, 0);
    printf("%d\n", ans);
    return 0;
}