// P-4-3. 十年磨一劍 (最少完成時間)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    vector<int> works(n);
    for (int i = 0; i < n; i++) cin >> works[i];
    sort(works.begin(), works.end());
    
    long long ans = 0, sum = 0;
    for (int work : works) {
        sum += work;
        ans += sum;
    }
    cout << ans << "\n";
    return 0;
}
