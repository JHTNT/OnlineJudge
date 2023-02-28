// Q-2-14. 水槽 (108 高中全國賽)
#include <bits/stdc++.h>
using namespace std;

int res[100005];
int _max = 2;
vector<pair<long long, int>> boards;

void calc(int left, int right, int index, long long water) {
    if (water == 0) return;
    if (right - left <= 1) {
        res[left] = water;
        return;
    }

    while (boards[_max].second <= left || boards[_max].second >= right) ++_max;
    long long h = boards[_max].first;
    int pos = boards[_max].second;
    if (water >= h * (right - left)) {
        int avg = water / (right - left);
        for (int i = left; i < right; ++i) res[i] = avg;
        return;
    }

    if (index < pos) {
        long long tmp = h * (pos - left);
        if (water >= tmp) {
            for (int i = left; i < pos; ++i) res[i] = h;
            calc(pos, right, pos, water - tmp);
        } else {
            calc(left, pos, index, water);
        }
    } else {
        long long tmp = (right - pos) * h;
        if (water >= tmp) {
            for (int i = pos; i < right; ++i) res[i] = h;
            calc(left, pos, pos - 1, water - tmp);
        } else {
            calc(pos, right, index, water);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, index, tmp;
    long long w;
    cin >> n >> index >> w;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        boards.push_back({tmp, i});
    }
    sort(boards.begin(), boards.end(), greater<>());
    calc(0, n, index, w);
    for (int i = 0; i < n; ++i) cout << res[i] << " ";
    return 0;
}