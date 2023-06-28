// Q-3-3. 加減乘除
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int res, tmp;  // tmp saves one number for operation
    string exp;

    cin >> exp;
    tmp = exp[0] - '0';
    for (int i = 1; i < exp.size(); i += 2) {
        char op = exp[i], num = exp[i + 1] - '0';
        if (op == '*') {
            tmp *= num;
        } else if (op == '/') {
            tmp /= num;
        } else {
            res += tmp;
            if (op == '+')
                tmp = num;
            else
                tmp = num * -1;
        }
    }
    res += tmp;
    cout << res;
    return 0;
}
