/*
 *
 Implement the following operations of a queue using stacks.

    push(x) -- Push element x to the back of queue.
    pop() -- Removes the element from in front of queue.
    peek() -- Get the front element.
    empty() -- Return whether the queue is empty.

Notes:

    You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
    Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
    You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
 * */
#include "header.h"

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        stack<int> tmp;
        while (!s.empty()) {
            tmp.push(s.top());
            s.pop();
        }
        s.push(x);
        while (!tmp.empty()) {
            s.push(tmp.top());
            tmp.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        s.pop();
    }

    // Get the front element.
    int peek(void) {
        return s.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty();
    }
private:
    stack<int> s;
};

int main(int argc, char **argv) {
    Queue q;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "empty") == 0) {
            cout << "empty? " << q.empty() << endl;
        } else if (strcmp(argv[i], "pop") == 0) {
            q.pop();
            cout << "pop" << endl;
        } else if (strcmp(argv[i], "peek") == 0) {
            cout << "peek " << q.peek() << endl;
        } else {
            int val = atoi(argv[i]);
            q.push(val);
            cout << "push " << val << endl;
        }
    }
    return 0;
}
