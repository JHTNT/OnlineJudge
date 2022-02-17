#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, char> mp {
    {'@', '~'}, {'#', '!'}, {'$', '@'}, {'%', '#'}, {'^', '$'}, {'&', '%'}, {'*', '^'},
    {'(', '&'}, {')', '*'}, {'_', '('}, {'+', ')'}, {'2', '`'}, {'3', '1'}, {'4', '2'},
    {'5', '3'}, {'6', '4'}, {'7', '5'}, {'8', '6'}, {'9', '7'}, {'0', '8'}, {'-', '9'},
    {'=', '0'}, {'e', 'q'}, {'r', 'w'}, {'t', 'e'}, {'y', 'r'}, {'u', 't'}, {'i', 'y'},
    {'o', 'u'}, {'p', 'i'}, {'[', 'o'}, {']', 'p'}, {'\\', '['}, {'d', 'a'}, {'f', 's'},
    {'g', 'd'}, {'h', 'f'}, {'j', 'g'}, {'k', 'h'}, {'l', 'j'}, {';', 'k'}, {'\'', 'l'},
    {'c', 'z'}, {'v', 'x'}, {'b', 'c'}, {'n', 'v'}, {'m', 'b'}, {',', 'n'}, {'.', 'm'}, {'/', ','}
};

/* 較方便的方法
string s[] = {
    "~!@#$%^&*()_+",
    "`1234567890-=",
    "qwertyuiop[]\\",
    "asdfghjkl;'",
    "zxcvbnm,./"
};
unordered_map<char, char> mp;
for (int i = 0; i < 5; i++) {
    for (int j = 2; j < s[i].size(); j++) {
        mp[s[i][j]] = s[i][j - 2];
    }
}
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;
    while (getline(cin, str)) {
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ') {
                cout << " ";
            } else {
                cout << mp[str[i]];
            }
        }
        cout << "\n";
    }
    return 0;
}