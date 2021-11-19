#include <stdio.h>
using namespace std;

int eval() {
    int val, x, y, z;
    char c;
    if (scanf("%d", &val)) return val;

    scanf("%c", &c);
    if (c == 'f') {
        x = eval();
        return 2 * x - 3;
    } else if (c == 'g') {
        x = eval();
        y = eval();
        return 2 * x + y - 7;
    } else {
        x = eval();
        y = eval();
        z = eval();
        return 3 * x - 2 * y + z;
    }
}

int main() {
    printf("%d\n", eval());
    return 0;
}