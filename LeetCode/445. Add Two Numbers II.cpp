#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

class Solution {
   public:
    Node *addTwoNumbers(Node *l1, Node *l2) {
        stack<int> s1, s2;

        while (l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int S = 0, carry = 0;
        Node *ans = new Node();
        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) {
                S += s1.top();
                s1.pop();
            }

            if (!s2.empty()) {
                S += s2.top();
                s2.pop();
            }

            ans->val = S % 10;
            carry = S / 10;
            S = carry;

            Node *next = new Node(carry, ans);
            ans = next;
        }
        return carry == 0 ? ans->next : ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n1, n2, tmp;
    Node *l1 = new Node();
    Node *l2 = new Node();
    Node *head1 = l1, *head2 = l2;

    cin >> n1 >> n2;
    for (int i = 0; i < n1; i++) {
        cin >> tmp;
        Node *next = new Node(tmp);
        head1->next = next;
        head1 = next;
    }

    for (int i = 0; i < n2; i++) {
        cin >> tmp;
        Node *next = new Node(tmp);
        head2->next = next;
        head2 = next;
    }

    Node *ans = Solution().addTwoNumbers(l1->next, l2->next);
    while (ans != nullptr) {
        cout << ans->val;
        ans = ans->next;
    }
    return 0;
}