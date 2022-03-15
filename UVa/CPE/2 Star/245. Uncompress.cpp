#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    vector<string> words;
    string tmp, s;
    while (getline(cin, tmp) && tmp[0] != '0') {
        for (int i = 0; i < tmp.size(); i++) {
            if (isalpha(tmp[i])) {
                s = "";
                while (isalpha(tmp[i])) {
                    s += tmp[i++];
                }
                i--;        // 抵銷最後一次 i++
                words.push_back(s);
                cout << s;
            } else if (isdigit(tmp[i])) {
                n = 0;
                while (isdigit(tmp[i])) {
                    n = n * 10 + tmp[i++] - '0';
                }
                i--;
                s = words[words.size() - n];
                words.erase(words.end() - n);       // erase 的參數類型為 iterator
                words.push_back(s);         // 將單字變為第一個
                cout << s;
            } else {
                cout << tmp[i];
            }
        }
        cout << "\n";       // getline 會移除最後的換行
    }
    return 0;
}