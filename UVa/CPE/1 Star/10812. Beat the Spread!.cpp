#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, s, d, a, b;
    cin >> n;
    while (n--) {
        cin >> s >> d;
        // 若 s < d 表示有分數為負，s + d 為奇數表示非整數解
        if (s < d || (s + d) % 2) {
            cout << "impossible\n";
        } else {
            cout << (s + d) / 2 << " " << (s - d) / 2 << "\n";      // 解一元二次
        }
    }
    return 0;
}