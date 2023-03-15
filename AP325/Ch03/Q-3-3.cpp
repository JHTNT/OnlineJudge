// Q-3-3. 加減乘除
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int res;
    string exp;
    stack<pair<char, int>> s;
    cin >> exp;
    res = exp[0] - '0';
    for (int i = 1; i < exp.size(); i += 2) {
        if (s.empty()) {
            if (exp[i] == '*') {
                res *= exp[i + 1] - '0';
            } else if (exp[i] == '/') {
                res /= exp[i + 1] - '0';
            } else {
                s.push({exp[i], exp[i + 1] - '0'});
            }
        } else {
            pair<char, int> tmp = s.top();
            s.pop();
            if (exp[i] == '*') {
                tmp.second *= exp[i + 1] - '0';
                s.push(tmp);
            } else if (exp[i] == '/') {
                tmp.second /= exp[i + 1] - '0';
                s.push(tmp);
            } else {
                if (tmp.first == '+')
                    res += tmp.second;
                else
                    res -= tmp.second;
                s.push({exp[i], exp[i + 1] - '0'});
            } 
        }
    }
    if (!s.empty()) {
        pair<char, int> tmp = s.top();
        if (tmp.first == '+')
            res += tmp.second;
        else
            res -= tmp.second;
    }
    cout << res;
    return 0;
}