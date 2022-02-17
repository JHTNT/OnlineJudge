#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, cnt;
    string bin;
    while (cin >> n) {
        if (n == 0) break;
        bin = "", cnt = 0;
        while (n) {
            cnt += (n & 1);         // n AND 1 為 1 表示二進位最後一位為 1
            bin += '0' + (n & 1);
            n >>= 1;        // 右移一位元（相當於除以 2）
        }
        reverse(bin.begin(), bin.end());
        cout << "The parity of " << bin << " is " << cnt << " (mod 2).\n";
    }
    return 0;
}