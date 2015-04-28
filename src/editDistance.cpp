/*
 * Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
 * */
#include "header.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();
        vector<vector<int> > f;
        vector<int> line1;
        for (int j = 0; j <= l2; j++) {
            line1.push_back(j);
        }
        f.push_back(line1);
        for (int i = 1; i <= l1; i++) {
            vector<int> line(l2 + 1, 10000000);
            f.push_back(line);
        }
        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                if (word1[i-1] == word2[j-1]) {
                    f[i][j] = f[i-1][j-1];
                } else {
                    f[i][j] = min(f[i-1][j-1] + 1, min(f[i][j-1] + 1,
                            f[i-1][j] + 1));
                }
            }
        }
        print_grid(f);
        return f[l1][l2];
    }
};

int main(int argc, char **argv) {
    Solution s;
    cout << s.minDistance(argv[1], argv[2]) << endl;
    return 0;
}
