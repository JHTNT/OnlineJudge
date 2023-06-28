// Q-3-5. 帶著板凳排雞排的高人 (APCS201902)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, h[200005];
    long long total = 0;
    set<pair<int, int>> st;  // {height, index}, ascending order

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];

    st.insert({h[1], 1});
    cin.ignore(100, ' ');  // ignore the first p
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        auto it = st.upper_bound({h[i] + p, i});
        if (it == st.end())
            total += i - 1;
        else
            total += i - it->second - 1;
        while (!st.empty() && st.begin()->first <= h[i]) {
            st.erase(st.begin());
        }
        st.insert({h[i], i});
    }
    cout << total;
    return 0;
}
