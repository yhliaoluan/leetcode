/*
 *Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 * */
#include "header.h"

class Solution {
public:
    int numTrees(int n) {
        int *f = (int *)malloc(sizeof(int) * n);
        memset(f, 0, sizeof(int) * n);
        return num(n, f);
    }
    int num(int n, int *f) {
        if (n <= 0) { return 1; }
        if (f[n - 1] == 0) {
            int count = 0;
            for (int i = 1; i <= n; i++) {
                count += num(i - 1, f) * num (n - i, f);
            }
            f[n - 1] = count;
        }
        return f[n - 1];
    }
};

int main(int argc, char **argv) {
    Solution s;
    cout << s.numTrees(atoi(argv[1])) << endl;
    return 0;
}
