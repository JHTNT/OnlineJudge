#include <cstdio>
#include <cmath>        // abs
using namespace std;

int main() {
    int n;
    bool jolly = true;
    while (scanf("%d", &n) != EOF) {
        int nums[n] = {0}, first, second;
        scanf("%d", &first);
        for (int i = 1; i < n; i++) {
            scanf("%d", &second);
            nums[abs(second - first)]++;        // 相鄰兩數絕對值的對應位置 +1
            first = second;
        }
        for (int i = 1; i < n; i++) {       // 必須 1 ~ n-1 恰出現一次
            if (nums[i] != 1) {
                jolly = false;
                break;
            }
        }
        if (jolly) printf("Jolly\n");
        else printf("Not jolly\n");
    }
    return 0;
}