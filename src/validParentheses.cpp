/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) {
            return false;
        }
        if (s.size() == 0) {
            return true;
        }
        stack<char> input;
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
            case '(':
            case '[':
            case '{':
                input.push(s[i]);
                break;
            case ')':
                if (input.size() == 0 || input.top() != '(') {
                    return false;
                }
                input.pop();
                break;
            case ']':
                if (input.size() == 0 || input.top() != '[') {
                    return false;
                }
                input.pop();
                break;
            case '}':
                if (input.size() == 0 || input.top() != '{') {
                    return false;
                }
                input.pop();
                break;
            }
        }
        return input.size() == 0;
    }
};

int main(int argc, char **argv) {
    Solution s;
    printf(s.isValid(argv[1]) ? "true\n" : "false\n");
    return 0;
}