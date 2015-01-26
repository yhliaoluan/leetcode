/*
 * Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 * */

#include <string>

using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int longest = 0;
        string longestStr;
        for (int i = 0; i < s.size(); i++) {
            int tmp = singleLongest(s, i);
            if (tmp > longest) {
                longest = tmp;
                longestStr = s.substr(i - longest / 2, longest);
            }

            tmp = doubleLongest(s, i);
            if (tmp > longest) {
                longest = tmp;
                longestStr = s.substr(i - longest / 2 + 1, longest);
            }
        }

        return longestStr;
    }
private:
    int singleLongest(string s, int index) {
        int left = index - 1;
        int right = index + 1;
        while (left >= 0 && right < s.size()) {
            if (s[left] != s[right]) {
                break;
            }
            left--;
            right++;
        }

        return right - left - 1;
    }

    int doubleLongest(string s, int index) {
        int left = index;
        int right = index + 1;
        while (left >= 0 && right < s.size()) {
            if (s[left] != s[right]) {
                break;
            }
            left--;
            right++;
        }

        return right - left - 1;
    }
};

int main(int argc, char **argv) {
    char buff[1024];
    scanf("%s", buff);
    Solution s;
    printf("%s\n", s.longestPalindrome(string(buff)).c_str());
}
