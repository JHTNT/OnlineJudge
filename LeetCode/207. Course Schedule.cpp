#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);

        for (auto prerequisite : prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
            indegree[prerequisite[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0) q.push(i);  // leaf node

        int nodesVisited = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            nodesVisited++;

            for (auto& neighbor : adj[node]) {
                // delete the edge "node -> neighbor"
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return nodesVisited == numCourses;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}