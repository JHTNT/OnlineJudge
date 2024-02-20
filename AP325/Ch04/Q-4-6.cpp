// Q-4-6. 少林寺的自動寄物櫃
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int w, f;
};

bool cmp(Item a, Item b) { return a.w * b.f < b.w * a.f; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    vector<Item> items(n);
    for (int i = 0; i < n; i++) cin >> items[i].w;
    for (int i = 0; i < n; i++) cin >> items[i].f;
    sort(items.begin(), items.end(), cmp);

    long long ans = 0, total_weight = 0;
    for (auto i : items) {
        ans += total_weight * i.f;
        total_weight += i.w;
    }
    cout << ans << "\n";
    return 0;
}
