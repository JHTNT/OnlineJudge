#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<char, vector<int>> mp {       // 每個音對應的鍵位
    {'c', {0, 1, 1, 1, 0, 0, 1, 1, 1, 1}},
    {'d', {0, 1, 1, 1, 0, 0, 1, 1, 1, 0}},
    {'e', {0, 1, 1, 1, 0, 0, 1, 1, 0, 0}},
    {'f', {0, 1, 1, 1, 0, 0, 1, 0, 0, 0}},
    {'g', {0, 1, 1, 1, 0, 0, 0, 0, 0, 0}},
    {'a', {0, 1, 1, 0, 0, 0, 0, 0, 0, 0}},
    {'b', {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}},
    {'C', {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}},
    {'D', {1, 1, 1, 1, 0, 0, 1, 1, 1, 0}},
    {'E', {1, 1, 1, 1, 0, 0, 1, 1, 0, 0}},
    {'F', {1, 1, 1, 1, 0, 0, 1, 0, 0, 0}},
    {'G', {1, 1, 1, 1, 0, 0, 0, 0, 0, 0}},
    {'A', {1, 1, 1, 0, 0, 0, 0, 0, 0, 0}},
    {'B', {1, 1, 0, 0, 0, 0, 0, 0, 0, 0}}
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    string s;
    cin >> t >> ws;
    while (t--) {
        getline(cin, s);
        int count[10] = {0}, status[10] = {0};          // status 為上一次的按鍵狀態
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < 10; j++) {
                if (mp[s[i]][j]) {
                    if (!status[j]) {        // 上一個音沒按則標記並 +1
                        status[j] = 1;
                        count[j]++;
                    }
                } else {
                    status[j] = 0;
                }
            }
        }
        for (int i = 0; i < 10; i++) {
            cout << count[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}