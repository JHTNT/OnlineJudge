#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int L, H, R, high[10005] = {0}, _min, _max = 0;
    cin >> L >> H >> R;
    _min = L, _max = R;
    for (int i = L; i < R; i++) {
        high[i] = max(high[i], H);
    }
    while (cin >> L >> H >> R) {
        _max = max(_max, R);
        for (int i = L; i < R; i++) {
            high[i] = max(high[i], H);
        }
    }
    H = 0;
    for (int i = _min; i <= _max; i++) {
        if (high[i] != H) {
            H = high[i];
            cout << i << " " << H << " ";
        }
    }
}