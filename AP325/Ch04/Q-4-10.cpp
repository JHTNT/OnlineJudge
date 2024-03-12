// Q-4-10. 恢復能量的白雲熊膽丸
#include <bits/stdc++.h>
using namespace std;

int p[100005], n, m;

bool check(int f) {
    int pill = m, energy = f;
    for (int i = 0; i < n; i++) {
        if (p[i] > f) return false;
        if (energy - p[i] < 0) {
            if (pill == 0) return false;
            energy = f;
            pill--;
        }
        energy -= p[i];
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int total = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        total += p[i];
    }

    int energy = 0;
    for (int jump = total / 2; jump > 0; jump >>= 1) {
        while (energy + jump < total && !check(energy + jump)) energy += jump;
    }
    cout << energy + 1 << "\n";
    return 0;
}
