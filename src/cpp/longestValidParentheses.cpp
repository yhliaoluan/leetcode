/*
 *Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4. 
 * */
#include <string>
#include <iostream>
#include <stack>
using namespace std;

#define INT_MIN 0x80000000
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> q;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                q.push(i);
            } else if (s[i] == ')') {
                if (q.empty() || (q.top() & INT_MIN) == INT_MIN) {
                    q.push(INT_MIN + i);
                } else {
                    q.pop();
                }
            }
        }
        int last = s.size();
        int m = 0;
        while (!q.empty()) {
            int i = q.top() & 0x7fffffff;
            m = max(last - i - 1, m);
            last = i;
            q.pop();
        }
        return max(last - 0, m);
    }
};

int main(int argc, char **argv) {
    if (argc > 1) {
        Solution s;
        cout << s.longestValidParentheses(argv[1]) << endl;
    }
    return 0;
}
