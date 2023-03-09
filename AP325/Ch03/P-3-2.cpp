// P-3-2. parenthesis matching, using STL
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str, pa = "([{)]}";
    bool error = false;
    while (cin >> str) {
        stack<int> s;
        error = false;
        for (char i : str) {
            int p = pa.find(i);
            if (p == -1) return 0;
            if (p < 3) {
                s.push(p);
            } else {
                if (s.empty() || p != s.top() + 3) {
                    error = true;
                    break;
                }
                s.pop();
            }
        }
        if (!s.empty()) error = true;
        cout << (error ? "no\n" : "yes\n");
    }
    return 0;
}