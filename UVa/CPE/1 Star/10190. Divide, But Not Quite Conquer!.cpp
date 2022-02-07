#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n, m;
    bool boring = false;
    while (scanf("%d %d", &n, &m) != EOF) {
        vector<int> ans;
        boring = false;
        if (n == 0 || m == 0) {
            boring = true;
        } else {
            ans.push_back(n);
            while (n > 1) {
                if (n % m == 0) {
                    n /= m;
                    ans.push_back(n);
                } else {        // 無法整除
                    boring = true;
                    break;
                }
            }
        }
        if (boring) {
            printf("Boring!\n");
        } else {
            for (auto i: ans) printf("%d ", i);
            printf("\n");
        }
    }
    return 0;
}