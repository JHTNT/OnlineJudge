#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
    char num[1005];
    while (gets(num) != NULL) {
        int even = 0, odd = 0, len;
        len = strlen(num);
        if (num[0] == '0' && len == 1) break;
        for (int i = 0; i < len; i++) {
            if (i % 2) {
                even += num[i] - '0';
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