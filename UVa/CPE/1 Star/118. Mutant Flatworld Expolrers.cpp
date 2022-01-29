#include <cstdio>
#include <utility>
#include <cstring>
using namespace std;

int main() {
    int m, n, x, y, scent[55][55];
    pair<int, int> _move[5];
    bool lost = false;
    char direction[] =  {'N', 'E', 'S', 'W'}, d, ch, command[100];      // 順時針 +1，逆時針 -1
    scanf("%d %d", &m, &n);
    // 定義 x, y 移動量
    _move[0].first = 0, _move[1].first = 1, _move[2].first = 0, _move[3].first = -1;
    _move[0].second = 1, _move[1].second = 0, _move[2].second = -1, _move[3].second = 0;

    while (scanf("%d %d %c", &x, &y, &d) != EOF) {
        lost = false;
        if (d == 'N') d = 0;
        else if (d == 'E') d = 1;
        else if (d == 'S') d = 2;
        else d = 3;

        scanf("%s", command);
        for (int i = 0; i < strlen(command) && !lost; i++) {
            if (command[i] == 'R') d = (d + 1) % 4;
            else if (command[i] == 'L') d = (d - 1 + 4) % 4;
            else if (command[i] == 'F') {
                x += _move[d].first;
                y += _move[d].second;
                if (x > m || x < 0 || y > n || y < 0) {
                    // 超出邊界就退回上一步
                    x -= _move[d].first;
                    y -= _move[d].second;
                    // 如果沒有做過標記就判定 LOST 並標記
                    if (!scent[x][y]) {
                        lost = true;
                        scent[x][y] = 1;
                    }
                }
            }
        }
        printf("%d %d %c", x, y, direction[d]);
        if (lost) printf(" LOST");
        printf("\n");
    }
    return 0;
}