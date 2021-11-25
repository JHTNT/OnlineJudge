#include <stdio.h>
using namespace std;

int eval() {
    int val, x, y;
    char c;
    if (scanf("%d", &val) == 1) return val;         // 若成功獲取整數接回傳

    scanf("%c", &c);        // 否則讀取一個字元並判斷函數
    if (c == 'f') {
        x = eval();
        return 2 * x - 1;
    } else if (c == 'g') {
        x = eval();
        y = eval();
        return x + 2 * y - 3;
    }
}

int main() {
    printf("%d\n", eval());
    return 0;
}