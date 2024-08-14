#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int apple[10];
    int h, cnt = 0;

    for (int i = 0; i < 10; i++) cin >> apple[i];
    cin >> h;
    h += 30;
    for (int i = 0; i < 10; i++) {
        if (h >= apple[i]) cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
