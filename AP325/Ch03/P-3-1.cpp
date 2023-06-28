// P-3-1. 樹的高度與根 (bottom-up) (APCS201710)
#include <bits/stdc++.h>
using namespace std;

int parent[100005], height[100005], degree[100005];  // degree is num of child

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    queue<int> bottom;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> degree[i];
        if (degree[i] == 0) bottom.push(i);
        for (int j = 0; j < degree[i]; j++) {
            cin >> tmp;
            parent[tmp] = i;  // set parent of every node
        }
    }

    int root, total = 0;
    while (true) {
        int v = bottom.front();
        bottom.pop();
        int p = parent[v];
        total += height[v];
        if (p == 0) {  // at root node
            root = v;
            break;
        }
        height[p] = max(height[p], height[v] + 1);
        if (--degree[p] == 0) bottom.push(p);
    }
    cout << root << "\n" << total;
    return 0;
}