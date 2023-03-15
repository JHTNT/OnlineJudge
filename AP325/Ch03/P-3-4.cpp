// P-3-4. 最接近的高人 (APCS201902, subtask)
#include <bits/stdc++.h>
using namespace std;

// stack approach
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, tmp;
    long long total = 0;
    stack<pair<int, int>> S;    // {height, index}

    cin >> n;
    S.push({INT_MAX, 0});
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        while (S.top().first <= tmp) S.pop();
        total += i - S.top().second;
        S.push({tmp, i});
    }
    cout << total;
    return 0;
}

// multimap approach
/*
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a[200005], n;
    long long total = 0;
    multimap<int, int> mp;
    a[0] = INT_MAX;

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i >= 0; i--) {
        auto it = mp.begin();
        while (it != mp.end() && it->first < a[i]) {
            total += it->second - i;
            it = mp.erase(it);  // return iterator following the last removed element
        }
        mp.insert({a[i], i});
    }
    cout << total;
    return 0;
}
*/