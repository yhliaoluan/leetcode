#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef INT_MIN
#define INT_MIN -2147483648
#endif

typedef struct Node {
    int val;
    int min;
    Node *next;
    Node *pre;
} Node;

class MinStack {
public:
    MinStack() : _cur(NULL) {}

    ~MinStack() {
        while (_cur != NULL) {
            Node *parent = _cur->pre;
            free(_cur);
            _cur = parent;
        }
    }
    void push(int x) {
        if (_cur == NULL) {
            _cur = create(x);
        } else {
            Node *cur = create(x);
            cur->min = min(cur->min, _cur->min);
            cur->pre = _cur;
            _cur->next = cur;
            _cur = cur;
        }
    }

    void pop() {
        if (_cur != NULL) {
            Node *parent = _cur->pre;
            free(_cur);
            _cur = parent;
        }
    }

    int top() {
        if (_cur != NULL) {
            return _cur->val;
        }
    }

    int getMin() {
        if (_cur != NULL) {
            return _cur->min;
        }
    }

private:
    Node *create(int val) {
        Node *node = (Node *)malloc(sizeof(Node));
        node->val = node->min = val;
        node->pre = node->next = NULL;
        return node;
    }
    int min(int x, int y) { return x < y ? x : y; }
    Node *_cur;
};
int main(int argc, char **argv) {
    MinStack ms;
    printf("push %d\n", 5);
    ms.push(5);
    printf("top: %d, min: %d\n", ms.top(), ms.getMin());
    printf("push %d\n", 3);
    ms.push(3);
    printf("top: %d, min: %d\n", ms.top(), ms.getMin());
    printf("push %d\n", 6);
    ms.push(6);
    printf("top: %d, min: %d\n", ms.top(), ms.getMin());
    printf("pop\n");
    ms.pop();
    printf("top: %d, min: %d\n", ms.top(), ms.getMin());
    printf("pop\n");
    ms.pop();
    printf("top: %d, min: %d\n", ms.top(), ms.getMin());
    return 0;
}
