// Q-1-4. 支點切割 (APCS201802) (@@)
#include <bits/stdc++.h>
using namespace std;

#define MAXN 50005

int N, K, p[MAXN];
long long lps[MAXN], rps[MAXN];

int cut(int left, int right, int depth) {
    if (depth > K || right - left < 2) return 0;

    long long delta = 0;
    lps[left] = 0;
    for (int i = left + 1; i <= right; i++) {
        delta += p[i - 1];
        lps[i] = lps[i - 1] + delta;
    }
    delta = 0;
    rps[right] = 0;
    for (int i = right - 1; i >= left; i--) {
        delta += p[i + 1];
        rps[i] = rps[i + 1] + delta;
    }

    long long mn = 2e18;        // 2^31 * 2^31
    int index = 0;
    for (int i = left + 1; i <= right - 1; i++) {
        // cost: the difference between left and right weighted sum
        long long cost = abs(rps[i] - lps[i]);
        if (cost < mn) {
            mn = cost;
            index = i;
        }
    }
    return p[index] + cut(left, index - 1, depth + 1) + cut(index + 1, right, depth + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> p[i];
    cout << cut(1, N, 1);
    return 0;
}