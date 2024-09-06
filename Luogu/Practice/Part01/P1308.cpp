#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0, first_pos = -1;
    string word, s;
    getline(cin, word);
    getline(cin, s);
    s += "  ";
    transform(word.begin(), word.end(), word.begin(),
              [](const unsigned char c) { return tolower(c); });
    transform(s.begin(), s.end(), s.begin(), [](const unsigned char c) { return tolower(c); });

    int n = s.size() - 2;
    for (int i = 0; i < n; i++) {
        if (s[i] == ' ') continue;
        int j = i;
        while (s[j] != ' ' && j <= n) j++;
        if (j - i != word.size()) {
            i = j;  // skip this word
            continue;
        }

        int start = i;
        bool same = true;
        for (int k = 0; k < word.size(); i++, k++) {
            if (s[i] != word[k]) {
                same = false;
                break;
            }
        }
        if (same) {
            if (first_pos == -1) first_pos = start;
            cnt++;
        }
    }

    if (first_pos == -1) {
        cout << -1;
    } else {
        cout << cnt << " " << first_pos << "\n";
    }
    return 0;
}
