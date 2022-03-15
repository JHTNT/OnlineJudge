// UVa 不明原因 WA
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

double charge[5][3] = {{0.1, 0.06, 0.02}, {0.25, 0.15, 0.05},
                       {0.53, 0.33, 0.13}, {0.87, 0.47, 0.17},
                       {1.44, 0.8, 0.3}};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int start_h, start_m, end_h, end_m, day, evening, night, tmp;
    double fee;
    char step, number[8];
    bool change_day = false;
    while (cin >> step) {
        if (step == '#') break;
        cin >> number >> start_h >> start_m >> end_h >> end_m;
        day = evening = night = fee = 0;
        change_day = false;
        // 剛好 24 小時
        if (start_h == end_h && start_m == end_m) change_day = true;
        // 是否換日
        if (start_h > end_h || (start_h == end_h && start_m > end_m)) {
            change_day = true;
            swap(start_h, end_h);
            swap(start_m, end_m);
        }
        // 將整點變為 60 分方便處理
        if (start_h != 0 && start_m == 0) {
            start_h--, start_m = 60;
        }
        if (end_h != 0 && end_m == 0) {
            end_h--, end_m = 60;
        }

        if (start_h >= 0 && start_h < 8) {
            if (end_h < 8) {
                tmp = (end_h - start_h) * 60 + end_m - start_m;
                night += tmp;
            } else {
                tmp = (7 - start_h) * 60 + 60 - start_m;
                night += tmp;
                start_h = 8, start_m = 0;
            }
        }
        if (start_h >= 8 && start_h < 18) {
            if (end_h < 18) {
                tmp = (end_h - start_h) * 60 + end_m - start_m;
                day += tmp;
            } else {
                tmp = (17 - start_h) * 60 + 60 - start_m;
                day += tmp;
                start_h = 18, start_m = 0;
            }
        }
        if (start_h >= 18 && start_h < 22) {
            if (end_h < 22) {
                tmp = (end_h - start_h) * 60 + end_m - start_m;
                evening += tmp;
            } else {
                tmp = (21 - start_h) * 60 + 60 - start_m;
                evening += tmp;
                start_h = 22, start_m = 0;
            }
        }
        if (start_h >= 22 && start_h < 24) {
            if (end_h < 24) {
                tmp = (end_h - start_h) * 60 + end_m - start_m;
                night += tmp;
            } else {
                tmp = (end_h - start_h) * 60 + end_m - start_m;
                night += tmp;
            }
        }
        if (change_day) {
            day = 600 - day;
            evening = 240 - evening;
            night = 600 - night;
        }
        fee += day * charge[step - 'A'][0];
        fee += evening * charge[step - 'A'][1];
        fee += night * charge[step - 'A'][2];
        cout << fixed << setprecision(2) << setw(10) << number << setw(6) << day
             <<  setw(6) << evening << setw(6) << night << setw(3) << step
             << setw(8) << fee << "\n";
    }
    return 0;
}