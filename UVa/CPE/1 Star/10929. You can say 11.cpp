#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
    char num[1005];         // 使用字元陣列方便輸入輸出
    while (fgets(num, 1001, stdin) != NULL) {       // 最多讀取 1000 位數，直到文件結束
        int even = 0, odd = 0, len;
        len = strlen(num) - 1;      // fgets 會讀入 \n
        if (num[0] == '0' && len == 1) break;       // 當只有一個 0 才 break，避免誤判
        for (int i = 0; i < len; i++) {
            if (i % 2) {
                even += num[i] - '0';       // 數字字元的 ACSII - 0 的 ACSII 就是實際數值
            } else {
                odd += num[i] -'0';
            }
        }

        if ((odd - even) % 11 == 0) {
            printf("%s is a multiple of 11.\n", num);
        } else {
            printf("%s is not a multiple of 11.\n", num);
        }
  }
  return 0;
}