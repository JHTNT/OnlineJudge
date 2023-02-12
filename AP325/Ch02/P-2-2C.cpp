// P-2-2C. 離散化 – set/map
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a[100005], n, k;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, int> S;
    for (int i = 0; i < n; i++) S[a[i]] = 0;
    int r = 0;
    for (auto item = S.begin(); item != S.end(); item++)
        item->second = r++;
    for (int i = 0; i < n - 1; i++) cout << S.find(a[i])->second << " ";
    cout << S.find(a[n - 1])->second;
    return 0;
}