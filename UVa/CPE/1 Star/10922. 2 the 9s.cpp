#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int sum, count;
    string num, temp;
    while (cin >> num) {
        if (num == "0") break;
        sum = 0, count = 0;
        // 加總每個位數
        for (int i = 0; i < num.size(); i++) {
            sum += num[i] - '0';
        }

        while (sum != 0 && sum != 9 && sum % 9 == 0) {
            count++;
            temp = to_string(sum);
            sum = 0;
            for (int i = 0; i < temp.size(); i++) {
                sum += temp[i] - '0';
            }
        }
        if (sum == 9) count++;

        if (count) {
            cout << num << " is a multiple of 9 and has 9-degree " <<
                count << ".\n";
        } else {
            cout << num << " is not a multiple of 9.\n";
        }
    }
    return 0;
}