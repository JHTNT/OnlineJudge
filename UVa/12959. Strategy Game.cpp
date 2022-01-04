#include <stdio.h>

int main() {
    int j, r, tmp;
    while (scanf("%d %d", &j, &r) == 2) {
        int player[505] = {0}, max = -1, winner = 0;
        while (r--) {
            for (int i = 0; i < j; i++) {
                scanf("%d", &tmp);
                player[i] += tmp;
            }
        }
        for (int i = 0; i < j; i++) {
            if (player[i] >= max) {
                winner = i + 1;
                max = player[i];
            }
        }
        printf("%d\n", winner);
    }
    return 0;
}