#include <iostream>
#include <iomanip>      // setprecision
#include <string>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n;
    cin.get();      // 去除讀取 n 留下的換行
    cin.get();      // 去除空行
    while (n--) {
        int sum = 0;
        map<string, int> mp;
        while (getline(cin, s) && s != "") {
            mp[s]++;        // 若在 map 裡直接 +1，否則建立後 +1
            sum++;          // 計算樹木總量
        }
        for (auto i : mp) {
            cout << i.first << " " << fixed << setprecision(4) <<
                <double>i.second / sum * 100 << "\n";
        }
        cout << "\n";
    }
    return 0;
}