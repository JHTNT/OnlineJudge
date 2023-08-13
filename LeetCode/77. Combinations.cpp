#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> combination(k);
        generateCombinations(1, n, k, combination, result);
        return result;
    }

   private:
    void generateCombinations(int start, int n, int k, vector<int> &combination,
                              vector<vector<int>> &result) {
        if (k == 0) {
            result.push_back(combination);
            return;
        }
        for (int i = start; i <= n; ++i) {
            combination[combination.size() - k] = i;
            generateCombinations(i + 1, n, k - 1, combination, result);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> ans = Solution().combine(n, k);
    for (vector<int> i : ans) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}