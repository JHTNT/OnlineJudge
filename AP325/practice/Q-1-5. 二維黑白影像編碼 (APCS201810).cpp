#include <stdio.h>

char S[1100000];
int i = 0, result = 0;

void matrix(int n) {
    for (int k = 0; k < 4; k++) {
        i++;
        if (S[i] == '1') {
            result += n * n;
        } else if (S[i] == '2') {
            matrix(n / 2);
        }
    }
}

int main() {
    int n;
    scanf("%s", &S);
    scanf("%d", &n);
    if (S[0] == '1') {
        result = n * n;
    } else if (S[0] == '0') {
        result = 0;
    } else {
        matrix(n / 2);
    }
    printf("%d", result);
}