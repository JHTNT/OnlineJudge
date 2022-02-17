#include <iostream>
#include <string>
#include <algorithm>        // min
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    while (cin >> a >> b) {
        int A[26] = {0}, B[26] = {0};       // 統計每個字母出現次數
        for (int i = 0; i < a.size(); i++) {
            A[a[i] - 'a']++;
        }
        for (int i = 0; i < b.size(); i++) {
            B[b[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            for (int j = min(A[i], B[i]); j > 0; j--) {
                cout << <char>('a' + i);
            }
        }
        cout << "\n";
    }
    return 0;
}