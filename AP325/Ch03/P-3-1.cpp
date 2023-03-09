// P-3-1. 樹的高度與根 (bottom-up) (APCS201710)
#include <bits/stdc++.h>
using namespace std;

#define N 100005

int parent[N], h[N], deg[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, tmp;
    queue<int> q;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> deg[i];
        if (deg[i] == 0) q.push(i);
        for (int j = 0; j < deg[i]; j++) {
            cin >> tmp;
            parent[tmp] = i;
        }
    }

    int root, total = 0;
    while (true) {
        int v = q.front();
        q.pop();
        int p = parent[v];
        total += h[v];
        if (p == 0) {
            root = v;
            break;
        }
        h[p] = max(h[p], h[v] + 1);
        if (--deg[p] == 0) q.push(p);
    }
    cout << root << "\n" << total;
    return 0;
}