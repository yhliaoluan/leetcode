/*
 *Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 * */
#include "header.h"

class DoubleLinkedNode {
public:
    int key;
    int val;
    DoubleLinkedNode *pre;
    DoubleLinkedNode *next;
    DoubleLinkedNode(int key, int val) : key(key), val(val), pre(NULL), next(NULL) { }
};

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity), head(-999, -999), tail(999, 999) {
        link(&head, &tail);
    }
    
    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) {
            return -1;
        }
        DoubleLinkedNode *node = it->second;
        link(node->pre, node->next);
        link(node, head.next);
        link(&head, node);
        return node->val;
    }
    
    void set(int key, int value) {
        auto it = map.find(key);
        DoubleLinkedNode *node = NULL;
        if (it == map.end()) {
            node = new DoubleLinkedNode(key, value);
            if (map.size() == capacity) {
                DoubleLinkedNode *lru = tail.pre;
                link(lru->pre, &tail);
                map.erase(lru->key);
                delete lru;
            }
            map.insert(make_pair(key, node));
        } else {
            node = it->second;
            node->val = value;
            link(node->pre, node->next);
        }
        link(node, head.next);
        link(&head, node);
    }

    void print_details() {
        cout << "map contains:";
        for (auto it : map) {
            cout << it.first << ":" << it.second->val << " ";
        }
        cout << endl;
        cout << "list from head to tail:";
        DoubleLinkedNode *cur = &head;
        while (cur) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
        cout << "list from tail to head:";
        cur = &tail;
        while (cur) {
            cout << cur->val << " ";
            cur = cur->pre;
        }
        cout << endl;
    }
private:
    int capacity;
    unordered_map<int, DoubleLinkedNode *> map;
    DoubleLinkedNode head;
    DoubleLinkedNode tail;

    void link(DoubleLinkedNode *pre, DoubleLinkedNode *next) {
        pre->next = next;
        next->pre = pre;
    }
};

static void assert(int value, int expect) {
    if (value != expect) {
        cout << "FAILED: value:" << value << " expect:" << expect << endl;
    } else {
        cout << "PASSED: value:" << value << " expect:" << expect << endl;
    }
}

int main(int argc, char **argv) {
    LRUCache cache(1);
    cache.set(2, 1);
    assert(cache.get(2), 1);
    cache.set(3, 2);
    assert(cache.get(2), -1);
    assert(cache.get(3), 2);
    return 0;
}
