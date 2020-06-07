#include "header.h"

class MinStack {
public:
    void push(int x) {
        values.push(x);
        mins.push(mins.empty() ? x : min(x, mins.top()));
    }

    void pop() {
        values.pop();
        mins.pop();
    }

    int top() {
        return values.top();
    }

    int getMin() {
        return mins.top();
    }
private:
    stack<int> values;
    stack<int> mins;
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
