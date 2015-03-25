/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        push(n, result, "", 0);
        return result;
    }
private:
    void push(int n, vector<string> &res, string str, int left) {
        if (n == 0 && left == 0) {
            res.push_back(str);
        }
        if (n > 0) {
            push(n - 1, res, string(str).append("("), left + 1);
        }

        if (left > 0) {
            push(n, res, string(str).append(")"), left - 1);
        }
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<string> result = s.generateParenthesis(atoi(argv[1]));
    for (auto it = result.begin(); it != result.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}