#include <iostream>
#include <string>
#include <sstream>      // stringstream
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x, sum, cur, len;
    vector<int> c;          // 係數 (coefficients)
    string s;
    while (cin >> x >> ws) {        // ws 用來忽略空白字元
        getline(cin, s);
        stringstream ss(s);         // stringstream 用來處理字串
        c.clear();      // 清空 vector（不回收記憶體）
        while (ss >> cur) {        // 以空格分隔逐段取出，並轉為 int
            c.push_back(cur);
        }
        sum = 0, cur = 1, len = c.size();
        // 常數微分不計；每次 cur 乘上 x 的值
        for (int i = len - 2; i >= 0; i--, cur *= x) {
            sum += (len - i - 1) * c[i] * cur;
        }
        cout << sum << "\n";
    }
    return 0;
}