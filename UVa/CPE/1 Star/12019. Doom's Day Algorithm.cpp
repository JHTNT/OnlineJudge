/*
2011 的 doomsday 是星期一，題目沒給三月的 doomsday，所以用第一個星期一代替。
用月份計算離 doomsday 剩幾天來推算星期幾。
*/
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, m, d, tmp;
    int dooms[12] = {10, 21, 7, 4, 9, 6, 11, 8, 5, 10, 7, 12};
    string days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday",
                      "Friday", "Saturday", "Sunday"};
    cin >> T;
    while (T--) {
        cin >> m >> d;
        tmp = (d - dooms[m - 1]) % 7;
        if (tmp < 0) {
            cout << days[tmp + 7] << "\n";
        } else {
            cout << days[tmp] << "\n";
        }
    }
    return 0;
}