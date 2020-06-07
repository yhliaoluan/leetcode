/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
 * */
#include <string>
#include <vector>
using namespace std;

string maps[9] = {
    "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        combine(result, "", digits.c_str());
        return result;
    }
private:
    void combine(vector<string> &result, string cur, const char *digits) {
        if (*digits == '\0') {
            if (cur.size() > 0) {
                result.push_back(cur);
            }
        } else {
            string map = maps[*digits - '2'];
            for (int i = 0; i < map.size(); i++) {
                combine(result, cur + map[i], digits + 1);
            }
        }
    }
};

static Solution s;

void print_result(string content) {
    printf("%s: ", content.c_str());
    vector<string> result = s.letterCombinations(content);
    for (int j = 0; j < result.size(); j++) {
        printf("\"%s\" ", result[j].c_str());
    }
    printf("\n");
}

int main(int argc, char **argv) {
    print_result("");
    for (int i = 1; i < argc; i++) {
        print_result(argv[i]);
    }
}
