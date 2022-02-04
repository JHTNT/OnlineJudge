#include <cstdio>
#include <vector>
using namespace std;

int main() {
    vector<int> fib;
    // 生成小於 10^8 的費氏數列
    int f0 = 0, f1 = 1, f2 = 1;
    for (; f2 <= 1e8;) {
        f2 = f0 + f1;
        fib.push_back(f2);
        f0 = f1;
        f1 = f2;
    }

    int n, x, temp;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        temp = x;
        int i = fib.size() - 1;
        vector<int> ans;
        while (fib[i] > temp) i--;          // 跳過大於 temp 的費氏數列
        for (; i >= 0; i--) {
            if (fib[i] <= temp) {
                temp -= fib[i--];
                ans.push_back(1);
                if (i >= 0) ans.push_back(0);       // 不會出現相鄰的 1
            } else ans.push_back(0);
        }
        printf("%d = ", x);
        for (auto k: ans) printf("%d", k);
        printf(" (fib)\n");
    }
    return 0;
}