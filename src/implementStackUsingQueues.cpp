/*
 * Implement the following operations of a stack using queues.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    empty() -- Return whether the stack is empty.

Notes:

    You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
    Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
    You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

Update (2015-06-11):
The class name of the Java function had been updated to MyStack instead of Stack.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and all test cases.
 * */
#include "header.h"

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        queue<int> tmp;
        while (q.size() > 1) {
            tmp.push(q.front());
            q.pop();
        }
        q.pop();
        swap(tmp, q);
    }

    // Get the top element.
    int top() {
        queue<int> tmp;
        while (q.size() > 1) {
            tmp.push(q.front());
            q.pop();
        }
        int val = q.front();
        q.pop();
        tmp.push(val);
        swap(tmp, q);
        return val;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
private:
    queue<int> q;
};

int main(int argc, char **argv) {
    Stack s;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "push") == 0) {
            int val = atoi(argv[++i]);
            s.push(val);
            cout << "push " << val << endl;
        } else if (strcmp(argv[i], "pop") == 0) {
            s.pop();
            cout << "pop" << endl;
        } else if (strcmp(argv[i], "top") == 0) {
            cout << "top " << s.top() << endl;
        } else if (strcmp(argv[i], "empty") == 0) {
            cout << "empty " << s.empty() << endl;
        }
    }
    return 0;
}
