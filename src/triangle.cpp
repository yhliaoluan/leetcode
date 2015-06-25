/*
 *Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
 * */
#include "header.h"

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        if (m == 0) { return 0; }
        int *pre = new int[m];
        int *f = new int[m];
        f[0] = triangle[0][0];
        for (int i = 1; i < m; i++) {
            swap(pre, f);
            f[0] = pre[0] + triangle[i][0];
            for (int j = 1; j < i; j++) {
                f[j] = min(pre[j - 1], pre[j]) + triangle[i][j];
            }
            f[i] = pre[i - 1] + triangle[i][i];
        }
        int value = f[0];
        for (int i = 1; i < m; i++) {
            value = min(value, f[i]);
        }
        delete[] pre;
        delete[] f;
        return value;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int> > triangle = read_grid<int>();
    cout << s.minimumTotal(triangle) << endl;
    return 0;
}
