/*
參考 https://blog.csdn.net/paschen/article/details/79840114
有 n 瓶可樂，由於能借空瓶，可以當作每次兌換只消耗 (3 - 1) 瓶。
所以 n 瓶可兌換 n / 2 次（向下取整），再加上原本的 n 瓶就是答案。
*/
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n) {
        cout << n + n / 2 << "\n";
    }
    return 0;
}