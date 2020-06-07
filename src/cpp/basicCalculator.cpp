/*
 *Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:

"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23

Note: Do not use the eval built-in library function. 
 * */
#include "header.h"

class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;
        for (int i = 0; i < s.size();) {
            if (s[i] == ' ') {
                i++;
            } else if (s[i] == '+' || s[i] == '-' || s[i] == '(') {
                ops.push(s[i]);
                i++;
            } else if (s[i] == ')') {
                ops.pop();
                while (!ops.empty() && ops.top() != '(')
                    calculate(nums, ops);
                i++;
            } else {
                nums.push(atoi(&s[i]));
                while (s[i] >= '0' && s[i] <= '9')
                    i++;
                if (!ops.empty() && ops.top() != '(')
                    calculate(nums, ops);
            }
        }
        return nums.top();
    }

    void calculate(stack<int> &nums, stack<char> &ops) {
        int num2 = nums.top();
        nums.pop();
        int num1 = nums.top();
        nums.pop();
        if (ops.top() == '+') {
            nums.push(num1 + num2);
        } else {
            nums.push(num1 - num2);
        }
        ops.pop();
    }
};

int main(int argc, char **argv) {
    cout << Solution().calculate(argv[1]) << endl;
    return 0;
}
