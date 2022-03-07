#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, N, P, h;
    cin >> T;
    while (T--) {
        int sum = 0;
        cin >> N >> P;
        int day[N + 1] = {0};       // index 0 不使用
        for (int i = 0; i < P; i++) {       // P 個政黨
            cin >> h;
            for (int j = h; j <= N; j += h) {
                day[j] = 1;
            }
        }
        // 星期五與星期六不算
        for (int i = 6; i <= N; i += 7) day[i] = 0;
        for (int i = 7; i <= N; i += 7) day[i] = 0;

        for (int i = 0; i <= N; i++) {
            sum += day[i];
        }
        cout << sum << "\n";
    }
    return 0;
}