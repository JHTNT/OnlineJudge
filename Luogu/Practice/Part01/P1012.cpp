#include <bits/stdc++.h>
using namespace std;

bool cmp(const string &a,const string &b) {
    // Cannot use (a > b).
    // Ex. "321" > "3", but "3212" < "3321"
    return a + b > b + a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    vector<string> nums;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        nums.push_back(s);
    }

    sort(nums.begin(), nums.end(), cmp);
    for (string s : nums) cout << s;
    return 0;
}
