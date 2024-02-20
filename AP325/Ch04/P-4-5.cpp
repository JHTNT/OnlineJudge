// P-4-5. 嵩山磨劍坊的問題 (加權最小完成時間)
#include <bits/stdc++.h>
using namespace std;

struct Order {
    int t, w;
};

bool cmp(Order a, Order b) { return a.t * b.w < b.t * a.w; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    vector<Order> orders(n);
    for (int i = 0; i < n; i++) cin >> orders[i].t;
    for (int i = 0; i < n; i++) cin >> orders[i].w;
    sort(orders.begin(), orders.end(), cmp);

    long long ans = 0, total_time = 0;
    for (auto o : orders) {
        total_time += o.t;
        ans += total_time * o.w;
    }
    cout << ans << "\n";
    return 0;
}
