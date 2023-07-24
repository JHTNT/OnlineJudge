#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int key;
    int val;
    Node *prev;
    Node *next;
    Node(int k, int v) : key(k), val(v) {}
};

class LRUCache {
   public:
    int capacity;
    unordered_map<int, Node *> cache;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->next = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;  // not found

        Node *target = cache[key];
        int value = target->val;

        // move the target node to the head
        removeNode(target);
        addNode(target);

        return value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node *target = cache[key];
            target->val = value;
            removeNode(target);
            addNode(target);
        } else {
            Node *target = new Node(key, value);
            if (cache.size() == capacity) {
                cache.erase(tail->prev->key);
                removeNode(tail->prev);
            }
            cache[key] = target;
            addNode(target);
        }
    }

   private:
    void addNode(Node *target) {
        target->prev = head;
        target->next = head->next;
        head->next->prev = target;
        head->next = target;
    }

    void removeNode(Node *target) {
        target->prev->next = target->next;
        target->next->prev = target->prev;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int capacity, key, value;
    string command;
    cin >> capacity;
    LRUCache *obj = new LRUCache(capacity);
    while (cin >> command) {
        if (command == "get") {
            cin >> key;
            cout << obj->get(key) << endl;
        } else if (command == "put") {
            cin >> key >> value;
            obj->put(key, value);
        }
    }
    return 0;
}
