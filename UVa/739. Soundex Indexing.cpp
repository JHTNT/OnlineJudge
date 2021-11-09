#include <bits/stdc++.h>
using namespace std;

map<char, int> code = {
    {'B', 1}, {'P', 1}, {'F', 1}, {'V', 1}, {'C', 2}, {'S', 2},
    {'K', 2}, {'G', 2}, {'J', 2}, {'Q', 2}, {'X', 2}, {'Z', 2},
    {'D', 3}, {'T', 3}, {'L', 4}, {'M', 5}, {'N', 5}, {'R', 6}
};

int main() {
    int num_count, len;         // num_count 用來計算字母後是否已經三位數
    char name[20];
    printf("         NAME                     SOUNDEX CODE\n");
    while (scanf("%s", name) != EOF) {
        len = strlen(name);
        num_count = 0;
        printf("         %-25s", name);
        printf("%c", name[0]);
        for (int i = 1; i < len; i++) {
            if (code[name[i]] && (code[name[i]] != code[name[i - 1]])) {
                // 不是排除的字母且與前一個字母編碼不相同
                printf("%d", code[name[i]]);
                num_count++;
                if (num_count == 3) break;
            }
        }
        for (; num_count < 3; num_count++) printf("0");         // 不足三位補 0
        printf("\n");
    }
    printf("                   END OF OUTPUT\n");
    return 0;
}