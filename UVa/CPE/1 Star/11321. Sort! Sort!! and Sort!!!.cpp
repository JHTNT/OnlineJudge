#include <iostream>
#include <algorithm>
using namespace std;

int M;

bool cmp(int a, int b) {        // true 不變，false 交換
    if ((a % M) != (b % M)) {       // 餘數不同則餘數較小的在前
        return (a % M) < (b % M);
    } else if ((a % 2) && (b % 2)) {        // 兩個皆為奇數則較大的在前
        return a > b;
    } else if ((a % 2 == 0) && (b % 2 == 0)) {      // 兩個皆為偶數則較小的在前
        return a < b;
    } else {                // 一奇一偶則奇數在前
        return (a % 2);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    while (cin >> N >> M) {
        if (N == 0 && M == 0) {
            cout << "0 0";
            break;
        } else {
            int num[N];
            for (int i = 0; i < N; i++) cin >> num[i];
            sort(num, num + N, cmp);
            cout << N << " " << M << "\n";
            for (int i = 0; i < N; i++) cout << num[i] << "\n";
        }
    }
}