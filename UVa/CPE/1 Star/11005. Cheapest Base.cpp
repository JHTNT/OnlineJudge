// 直接窮舉
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, Q, n, tmp, cheap, c;
    map<int, int> cost, result;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cost.clear();
        for (int j = 0; j < 36; j++) cin >> cost[j];
        cin >> Q;
        cout << "Case " << i << ":\n";
        while (Q--) {
            cin >> n;
            cheap = 0x7FFFFFFF;         // int 上限
            for (int j = 2; j <= 36; j++) {
                tmp = n, c = 0;
                while (tmp) {
                    c += cost[tmp % j];
                    tmp /= j;
                }
                result[j] = c;
                cheap = min(cheap, c);
            }
            cout << "Cheapest base(s) for number " << n << ":";
            for (int j = 2; j <= 36; j++) {
                if (result[j] == cheap) cout << " " << j;
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}