// P-4-2. 笑傲江湖之三戰
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    vector<int> enemy(n);
    vector<int> self(n);
    for (int i = 0; i < n; i++) cin >> enemy[i];
    for (int i = 0; i < n; i++) cin >> self[i];

    int win = 0;
    sort(enemy.begin(), enemy.end());
    sort(self.begin(), self.end());
    for (int i = 0, j = 0; i < n; i++) {
        // i = self, j = enemy
        if (self[i] > enemy[j]) win++, j++;
    }
    cout << win << "\n";
    return 0;
}
