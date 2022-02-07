#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second > b.second;         // 數量相同以 ASCII 排序
    else return a.first < b.first;
}

int main() {
    char str[1001];
    while (fgets(str, 1000, stdin)) {
        str[strlen(str) - 1] = '\0';
        pair<int, int> a[128];
        for (int i = 0; i < 128; i++) a[i] = {0, i};
        for (int i = 0; i < strlen(str); i++) {
            a[str[i]].first++;
        }
        sort(a, a + 128, cmp);
        for (auto i: a) {
            if (i.first > 0) printf("%d %d\n", i.second, i.first);
        }
        printf("\n");
    }
    return 0;
}