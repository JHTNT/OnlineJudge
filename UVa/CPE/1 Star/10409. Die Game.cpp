#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, temp;
    string s;
    while (cin >> n) {
        if (n == 0) break;
        // 分別代表 Top (0), North (1), West (2), South (3), East (4), Bottom (5)
        int d[6] = {1, 2, 3, 5, 4, 6};
        while (n--) {
            cin >> s;
            // 根據轉向改變各面的數字
            if (s == "east") {
                temp = d[4], d[4] = d[0], d[0] = d[2], d[2] = d[5], d[5] = temp;
            } else if (s == "south") {
                temp = d[3], d[3] = d[0], d[0] = d[1], d[1] = d[5], d[5] = temp;
            } else if (s == "west") {
                temp = d[2], d[2] = d[0], d[0] = d[4], d[4] = d[5], d[5] = temp;
            } else if (s == "north") {
                temp = d[1], d[1] = d[0], d[0] = d[3], d[3] = d[5], d[5] = temp;
            }
        }
        cout << d[0] << "\n";
    }
    return 0;
}