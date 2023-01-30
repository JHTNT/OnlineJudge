// Q-1-8. 子集合的和 (APCS201810, subtask)
#include <bits/stdc++.h>
using namespace std;

int n, MAX = 0, P, nums[26];

void rec(int i, int s) {
    if (s > P) return;
    if (i >= n) {
        if (s > MAX && s < P) MAX = s;
        return;
    }
    rec(i + 1, s + nums[i]);
    rec(i + 1, s);
    return;
}

int main() {
    cin >> n >> P;
    for (int i = 0; i < n; i++) cin >> nums[i];
    rec(0, 0);
    cout << MAX;
    return 0;
}