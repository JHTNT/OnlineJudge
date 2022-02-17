#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s, tmp;
    map<string, int> mp;        // 利用 map 的自動按照字典順序排序
    cin >> n;
    while (n--) {
        cin >> s >> tmp >> tmp;         // 名字為無關資訊
        mp[s]++;
    }
    for (auto i : mp) {
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}