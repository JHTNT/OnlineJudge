#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0, S = 0;
    string isbn;
    getline(cin, isbn);

    for (int i = 0; i < 12; i++) {
        char c = isbn[i];
        if (c == '-') continue;
        cnt++;
        S += (c - '0') * cnt;
    }
    char last = S % 11 < 10 ? '0' + S % 11 : 'X';
    if (last == isbn[12]) {
        cout << "Right";
    } else {
        isbn[12] = last;
        cout << isbn;
    }
    return 0;
}
