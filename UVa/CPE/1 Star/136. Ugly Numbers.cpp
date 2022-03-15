/*
計算第 i 項時，從前面 i - 1 項分別找出 x/y/z，
使 x/y/z 乘以 2/3/5 為大於 ugly[i - 1] 的最小值，
則 min(x * 2, y * 3, z * 5) 即為第 i 項。
同時記錄 x/y/z 的位置供下一輪使用，
因為小於 x/y/z 的值乘以 2/3/5 必不可能大於 ugly[i]。
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n2 = 0, n3 = 0, n5 = 0, ugly[1500] = {1};
    for (int i = 1; i < 1500; i++) {
        while (ugly[n2] * 2 <= ugly[i - 1]) n2++;
        while (ugly[n3] * 3 <= ugly[i - 1]) n3++;
        while (ugly[n5] * 5 <= ugly[i - 1]) n5++;
        ugly[i] = min({ugly[n2] * 2, ugly[n3] * 3, ugly[n5] * 5});
    }
    cout << "The 1500'th ugly number is " << ugly[1499] << ".\n";
    return 0;
}