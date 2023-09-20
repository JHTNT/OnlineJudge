#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* partition(ListNode* head, int x) {
        ListNode small(0), large(0);
        ListNode* p1 = &small;
        ListNode* p2 = &large;

        while (head) {
            if (head->val < x) {
                p1->next = head;
                p1 = p1->next;
            } else {
                p2->next = head;
                p2 = p2->next;
            }
            head = head->next;
        }

        p1->next = large.next;
        p2->next = nullptr;
        return small.next;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}