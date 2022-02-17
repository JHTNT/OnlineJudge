/*
設題目給定的四個點為 A、B、C、D，B 與 D 重合，
第四個點即為 (xA + xC - xB, yA + yC - yB)。
A 與 B、C 與 D 分別為兩線段的兩端，不可能重合，
因此只有四種重合可能：AC、AD、BC、BD
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double x[4], y[4];
    while (cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2] >> x[3] >> y[3]) {
        cout << fixed << setprecision(3);       // 設定精度（直到再次變更前都有效）
        // 判斷重合的點是哪個
        if (x[0] == x[2] && y[0] == y[2]) {             // AC
            cout << x[1] + x[3] - x[0] << " " << y[1] + y[3] - y[0] << "\n";
        } else if (x[0] == x[3] && y[0] == y[3]) {      // AD
            cout << x[1] + x[2] - x[0] << " " << y[1] + y[2] - y[0] << "\n";
        } else if (x[1] == x[2] && y[1] == y[2]) {      // BC
            cout << x[0] + x[3] - x[1] << " " << y[0] + y[3] - y[1] << "\n";
        } else if (x[1] == x[3] && y[1] == y[3]) {      // BD
            cout << x[0] + x[2] - x[1] << " " << y[0] + y[2] - y[1] << "\n";
        }
    }
    return 0;
}