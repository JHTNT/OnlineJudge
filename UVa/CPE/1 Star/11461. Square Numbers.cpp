#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, x, y;
    while (cin >> a >> b) {
        if (a == 0 && b == 0) break;
        x = sqrt(a);
        y = sqrt(b);
        if (x * x != a) x++;        // int 會捨去小數點，要確認是否剛好
        cout << y - x + 1 << "\n";
    }
    return 0;
}