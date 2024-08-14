#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, cnt = 0;
    int nums[100], check[100] = {0};
    cin >> n;

    for (int i = 0; i < n; i++) cin >> nums[i];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (i == j) continue;
            int s = nums[i] + nums[j];
            for (int k = 0; k < n; k++) {
                if (check[k] == 0 && s == nums[k]) {
                    check[k] = 1;
                    cnt++;
                    break;
                } 
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
