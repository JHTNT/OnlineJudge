#include <cstdio>
#include <algorithm>        // swap
using namespace std;

int main() {
    int n, l, train[55], count;
    scanf("%d", &n);

    while (n--) {
        count = 0;
        scanf("%d", &l);
        for (int i = 0; i < l; i++) scanf("%d", &train[i]);
        for (int i = 0; i < l; i++) {       // bubble sort
            for (int j = 0; j < l - i - 1; j++) {
                if (train[j] > train[j + 1]) {
                    swap(train[j], train[j + 1]);
                    count++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n", count);
    }
    return 0;
}