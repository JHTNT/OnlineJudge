#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    stack<int> nums;
    int n;
    while (cin >> n && n != 0) nums.push(n);

    while (!nums.empty()) {
        cout << nums.top() << " ";
        nums.pop();
    }
    return 0;
}
