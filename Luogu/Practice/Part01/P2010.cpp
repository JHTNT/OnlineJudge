#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // 02/29 only fit on 9220/02/29
    int days[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int start, end, cnt = 0;
    cin >> start >> end;

    for (int i = 1; i <= 12; i++) {
        for (int j = 1; j <= days[i]; j++) {
            int num = j % 10 * 10000000 + (j / 10) * 1000000 + i % 10 * 100000 + (i / 10) * 10000 +
                      i * 100 + j;

            if (num >= start && num <= end) cnt++;
        }
    }
    cout << cnt;
    return 0;
}
