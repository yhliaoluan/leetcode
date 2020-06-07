/*
 *Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1

Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2

Output: [0, 2]

Example 2

Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10

Output: [-34, -14, -10, -10, 10]
 * */
#include "header.h"

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '+' ||
                input[i] == '-' ||
                input[i] == '*') {
                vector<int> res1 = diffWaysToCompute(input.substr(0, i));
                vector<int> res2 = diffWaysToCompute(input.substr(i + 1));
                for (int a : res1) {
                    for (int b : res2) {
                        if (input[i] == '+') res.push_back(a + b);
                        else if (input[i] == '-') res.push_back(a - b);
                        else res.push_back(a * b);
                    }
                }
            }
        }
        if (res.empty()) {
            res.push_back(stoi(input));
        }
        return res;
    }
};

int main(int argc, char **argv) {
    print_vector(Solution().diffWaysToCompute(argv[1]));
    return 0;
}
