#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int type, cnt = 0;
    string S;
    cin >> S >> type;

    int n = S.size();
    // L, L', R, R'
    vector<int> max_state = {0, 0, 0, 0};
    vector<int> curr_max_state = {0, 0, 0, 0};
    for (int i = 0; i < n; i++) {
        vector<int> curr_state = {0, 0, 0, 0};

        if (S[i] == '(') {
            i++;
            while (S[i] != ')') {
                if (i + 1 < n && S[i + 1] == '\'') {
                    if (S[i] == 'L') {
                        curr_state[1] = 1;
                    } else if (S[i] == 'R') {
                        curr_state[3] = 1;
                    }
                    i += 2;
                } else {
                    if (S[i] == 'L') {
                        curr_state[0] = 1;
                    } else if (S[i] == 'R') {
                        curr_state[2] = 1;
                    }
                    i++;
                }
            }
        } else {
            if (i + 1 < n && S[i + 1] == '\'') {
                if (S[i] == 'L') {
                    curr_state[1] = 1;
                } else if (S[i] == 'R') {
                    curr_state[3] = 1;
                }
                i++;
            } else {
                if (S[i] == 'L') {
                    curr_state[0] = 1;
                } else if (S[i] == 'R') {
                    curr_state[2] = 1;
                }
            }
        }
        cnt++;

        for (int i = 0; i < 4; i++) {
            if (curr_state[i]) {
                curr_max_state[i]++;
            } else {
                max_state[i] = max(max_state[i], curr_max_state[i]);
                curr_max_state[i] = 0;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        max_state[i] = max(max_state[i], curr_max_state[i]);
        curr_max_state[i] = 0;
    }
    
    cout << cnt;
    if (type) {
        cout << "\n";
        for (int i : max_state) cout << i << " ";
    }
    return 0;
}
