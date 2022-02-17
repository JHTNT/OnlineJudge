#include <iostream>
#include <set>      // set 內元素不重複
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, tmp, T = 1;
    set<int> sum;
    while (cin >> N) {
        int b[N];
        bool repeat = false;
        sum.clear();
        for (int i = 0; i < N; i++) cin >> b[i];
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                tmp = b[i] + b[j];
                if (sum.count(tmp)) {       // 只會回傳存在 (1) 或不存在 (0)
                    repeat = true;
                    break;
                }
                sum.insert(tmp);
            }
            if (repeat) break;
        }
        cout << "Case #" << T++ << ": ";
        if (repeat) {
            cout << "It is not a B2-Sequence.\n\n";
        } else {
            cout << "It is a B2-Sequence.\n\n";
        }
    }
    return 0;
}