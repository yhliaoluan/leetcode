/*
 *Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:

"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5

Note: Do not use the eval built-in library function.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
 * */
#include "header.h"

class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                int num = 0;
                while (s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + s[i++] - '0';
                }
                i--;
                nums.push(num);
                if (!ops.empty() && (ops.top() == '*' || ops.top() == '/'))
                    calculate(nums, ops);
            } else if (s[i] == '+' || s[i] == '-' || s[i] == '*'
                || s[i] == '/' || s[i] == '(') {
                if (s[i] == '+' || s[i] == '-') {
                    if (!ops.empty() && (ops.top() == '+' || ops.top() == '-'))
                        calculate(nums, ops);
                }
                ops.push(s[i]);
            } else if (s[i] == ')') {
                if (ops.top() != '(')
                    calculate(nums, ops);
                ops.pop();
                if (!ops.empty() && (ops.top() == '*' || ops.top() == '/'))
                    calculate(nums, ops);
            }
        }
        if (!ops.empty())
            calculate(nums, ops);
        return nums.top();
    }
private:
    void calculate(stack<int> &nums, stack<char> &ops) {
        int num1 = nums.top();
        nums.pop();
        int num2 = nums.top();
        nums.pop();
        char c = ops.top();
        ops.pop();
        if (c == '+') {
            nums.push(num1 + num2);
        } else if (c == '-') {
            nums.push(num2 - num1);
        } else if (c == '*') {
            nums.push(num1 * num2);
        } else if (c == '/') {
            nums.push(num2 / num1);
        }
    }
};

int main(int argc, char **argv) {
    cout << Solution().calculate(argv[1]) << endl;
    return 0;
}
