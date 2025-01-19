#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> students(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> students[i][j];
        }
    }

    vector<int> p_sum(m, 0);
    for (int t = 0; t < k; t++) {
        int max_sum = 0, min_sum = INT_MAX;
        for (int j = 0; j < m; j++) {
            p_sum[j] = 0;
            for (int i = 0; i < n; i++) {
                p_sum[j] += students[i][j];
            }
            max_sum = max(max_sum, p_sum[j]);
            min_sum = min(min_sum, p_sum[j]);
        }

        priority_queue<int> line;
        for (int j = 0; j < m; j++) {
            if (p_sum[j] == max_sum || p_sum[j] == min_sum) {
                for (int i = 0; i < n; i++) {
                    line.push(students[i][j]);
                    students[i][j] = -1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (i % 2) {
                for (int j = m - 1; j >= 0; j--) {
                    if (students[i][j] == -1) {
                        students[i][j] = line.top();
                        line.pop();
                    }
                }
            } else {
                for (int j = 0; j < m; j++) {
                    if (students[i][j] == -1) {
                        students[i][j] = line.top();
                        line.pop();
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << students[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
