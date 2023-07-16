#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recursion) {
        if (recursion[node]) return true;
        if (visited[node]) return false;

        visited[node] = true;
        recursion[node] = true;
        for (int i : adj[node])
            if (dfs(i, adj, visited, recursion)) return true;

        recursion[node] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j : graph[i]) {
                adj[i].push_back(j);
            }
        }

        vector<bool> visited(n, false);
        vector<bool> recursion(n, false);  // recursion stack
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                dfs(i, adj, visited, recursion);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!recursion[i]) ans.push_back(i);
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}