#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int row = 0, col = 0;
    char str[105][105];
    while (fgets(str[col], 105, stdin)) {
        str[col][strlen(str[col]) - 1] = '\0';          // 替換結尾的換行字元
        row = max(row, (int) strlen(str[col]));
        col++;
    }
    for (int j = 0; j < row; j++) {
        for (int i = col - 1; i >= 0; i--) {
            if (j >= strlen(str[i])) printf(" ");
            else printf("%c", str[i][j]);
        }
        printf("\n");
    }
    return 0;
}