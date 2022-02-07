/*
給定 N 進制的 R，保證 R 能被 N - 1 整除，求最小 N
若 R 能被 N - 1 整除，則 R 的各個位數總和也能被 N - 1 整除
*/
#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    freopen("test.out","w", stdout);
    int sum, max, temp, i;
    char num[10000];
    while (fgets(num, 10000, stdin)) {
        sum = 0, max = 1;       // 至少為二進制，所以 N - 1 最小為 1
        num[strlen(num) - 1] = '\0';
        for (i = 0; i < strlen(num); i++) {
            if (isdigit(num[i])) temp = num[i] - '0';
            else if (isupper(num[i])) temp = num[i] - 'A' + 10;
            else if (islower(num[i])) temp = num[i] - 'a' + 36;
            else continue;

            if (max < temp) max = temp;
            sum += temp;        // 加總每個位數
        }
        for (i = max; i < 62; i++) {
            if ((sum % i) == 0) {
                printf("%d\n", i + 1);      // N - 1 是否能整除 R
                break;
            }
        }
        if (i == 62) printf("such number is impossible!\n");        // 沒有符合的 N
    }
    return 0;
}