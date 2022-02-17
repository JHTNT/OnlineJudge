#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, a, b, count;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> a >> b;
        // 將邊界都變為奇數
        if (a % 2 == 0) a++;
        if (b % 2 == 0) b--;
        count = (b - a) / 2 + 1;
        cout << "Case " << i << ": ";
        cout << (a + b) / 2 * count << "\n";        // 求平均後乘奇數個數
    }
    return 0;
}