#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int distinct(int in[], int out[], int n) {
    if (n < 1) return 0;
    vector<int> v(in, in + n);          // 複製 in[] 到 v
    sort(v.begin(), v.end());
    int num = 0;
    for (int i = 0; i < n; i++) {
        out[num++] = v[i];
        while (v[i + 1] == v[i]) i++;       // 下一個數字重複就跳過
    }
    return num;
}

int main() {
    int in[100010], out[100010], n, count;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", in + i);
    }
    count = distinct(in, out, n);
    printf("%d\n", count);
    for (int i = 0; i < count - 1; i++) {
        printf("%d ", out[i]);
    }
    printf("%d\n", out[count - 1]);
    return 0;
}