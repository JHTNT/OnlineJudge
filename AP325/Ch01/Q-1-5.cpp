// Q-1-5. 二維黑白影像編碼 (APCS201810)
#include <bits/stdc++.h>
using namespace std;

string S;
int i = 0, res = 0;

void cut(int n) {
    for (int j = 0; j < 4; j++) {
        i++;
        if (S[i] == '1')
            res += n * n;
        else if (S[i] == '2')
            cut(n / 2);
    }
}

int main() {
    int n;
    cin >> S >> n;
    if (S[0] == '0') {
        cout << 0;
    } else if (S[0] == '1') {
        cout << n * n;
    } else {
        cut(n / 2);
        cout << res;
    }
    return 0;
}