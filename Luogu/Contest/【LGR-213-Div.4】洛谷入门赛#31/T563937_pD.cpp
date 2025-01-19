#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, tmp;
    cin >> n;
    vector<int> fast, slow;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp <= 15) {
            fast.push_back(tmp);
        } else {
            slow.push_back(tmp);
        }
    }

    for (int i : fast) {
        cout << i << " ";
    }
    for (int i : slow) {
        cout << i << " ";
    }
    return 0;
}
