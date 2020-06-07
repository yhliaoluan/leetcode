/*
 *Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 * */
#include "header.h"

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (string s : tokens) {
            if (s.compare("+") == 0) {
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
                nums.push(a + b);
            } else if (s.compare("-") == 0) {
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
                nums.push(a - b);
            } else if (s.compare("*") == 0) {
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
                nums.push(a * b);
            } else if (s.compare("/") == 0) {
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
                nums.push(a / b);
            } else {
                nums.push(stoi(s));
            }
        }
        return nums.top();
    }
};

int main(int argc, char **argv) {
    vector<string> tokens;
    for (int i = 1; i < argc; i++) {
        tokens.push_back(argv[i]);
    }
    Solution s;
    cout << s.evalRPN(tokens) << endl;
}
