#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<string> s1;
    vector<string> s2;
    string tmp;
    int sec;
    while (getline(cin, tmp) && tmp != "EOF") {
        string real;
        for (char c : tmp) {
            if (c == '<') {
                if (!real.empty()) real.pop_back();
            } else {
                real.push_back(c);
            }
        }
        s1.push_back(real);
    }
    while (getline(cin, tmp) && tmp != "EOF") {
        string real;
        for (char c : tmp) {
            if (c == '<') {
                if (!real.empty()) real.pop_back();
            } else {
                real.push_back(c);
            }
        }
        s2.push_back(real);
    }
    cin >> sec;

    int cnt = 0;
    for (int i = 0; i < min(s1.size(), s2.size()); i++) {
        string example = s1[i];
        string input = s2[i];

        for (int j = 0; j < min(example.size(), input.size()); j++) {
            if (example[j] == input[j]) {
                cnt++;
            }
        }
    }
    cout << static_cast<int>(cnt * 60.0 / sec + 0.5);
    return 0;
}
