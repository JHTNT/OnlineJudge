#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;

bool cmp(pair<int, char> a, pair<int, char> b) {
    if (a.first != b.first) return a.first > b.first;
    else return a.second < b.second;        // 數量相同則字元較小在前
}

int main() {
    int n;
    char str[1000];
    vector<pair<int, char>> alpha(26);
    for (int i = 0; i < 26; i++) {
        alpha[i] = {0, 'A' + i};
    }
    scanf("%d\n", &n);          // 消除 n 之後的換行符號
    while (n--) {
        fgets(str, 1000, stdin);
        for (int i = 0; i < strlen(str); i++) {
            if (isalpha(str[i])) {
                alpha[toupper(str[i]) - 'A'].first++;
            }
        }
    }
    sort(alpha.begin(), alpha.end(), cmp);
    for (auto i: alpha) {
        if (i.first > 0) printf("%c %d\n", i.second, i.first);
    }
    return 0;
}