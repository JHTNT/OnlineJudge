// P-3-2. 括弧配對
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string input;
    string pattern = "([{)]}";

    while (cin >> input) {
        bool match = true;
        stack<int> S;
        for (char i : input) {
            int p = pattern.find(i);
            if (p >= 3) {  // right
                if (S.empty() || S.top() != p - 3) {
                    match = false;
                    break;
                } else {
                    S.pop();
                }
            } else {
                S.push(p);
            }
        }
        if (!S.empty()) match = false;
        cout << (match ? "Yes\n" : "No\n");
    }
    return 0;
}