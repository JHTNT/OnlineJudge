#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int king, queen, goal, kx, ky, qx, qy, gx, gy;
    bool move;
    while (cin >> king >> queen >> goal) {
        // 位置重合
        if (king == queen) {
            cout << "Illegal state\n";
            continue;
        }
        // 轉為座標
        kx = king / 8, ky = king % 8;
        qx = queen / 8, qy = queen % 8;
        gx = goal / 8, gy = goal % 8;
        // 目標不在移動範圍內
        if ((qx != gx && qy != gy) || king == goal || queen == goal) {
            cout << "Illegal move\n";
            continue;
        }
        // king 在 queen 跟 goal 中間
        if (qx == gx && kx == gx) {
            if (qy > gy && qy > ky && ky > gy) {
                cout << "Illegal move\n";
                continue;
            } else if (qy < gy && qy < ky && ky < gy) {
                cout << "Illegal move\n";
                continue;
            }
        } else if (qy == gy && ky == gy) {
            if (qx > gx && qx > kx && kx > gx) {
                cout << "Illegal move\n";
                continue;
            } else if (qx < gx && qx < kx && kx < gx) {
                cout << "Illegal move\n";
                continue;
            }
        }
        // goal 是 king 的移動範圍
        if ((abs(gx - kx) == 1 && ky == gy) || (abs(gy - ky) == 1 && kx == gx)) {
            cout << "Move not allowed\n";
            continue;
        }
        // 判斷移動後 king 是否被困住，至少有一格可動就 continue
        move = false;
        if (kx + 1 < 8 && kx + 1 != gx && ky != gy) move = true;
        if (kx - 1 >= 0 && kx - 1 != gx && ky != gy) move = true;
        if (ky + 1 < 8 && ky + 1 != gy && kx != gx) move = true;
        if (ky - 1 >= 0 && ky - 1 != gy && kx != gx) move = true;

        if (move) {
            cout << "Continue\n";
        } else {
            cout << "Stop\n";
        }
    }
    return 0;
}