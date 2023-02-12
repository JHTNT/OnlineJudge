// P-2-11. 最接近的區間和
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, psum = 0, best = 0, tmp;
    set<int> ps({0});
    cin >> n >> k;
    for (int r = 0; r < n; r++) {
        cin >> tmp;
        psum += tmp;
        auto it = ps.lower_bound(psum - k);
        if (it != ps.end())
            best = max(best, psum - *it);
        ps.insert(psum);
    }
    cout << best;
    return 0;
}