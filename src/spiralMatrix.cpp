/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/
#include "header.h"
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        result = matrix[0];  // no need to check the first row
        int dirs[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};  // direction offsets
        int d = 0;  // direction index
        int m = matrix.size();
        int n = matrix[0].size();
        int pos[2] = {0, n - 1};  // start from the top right corner
        int i = (m - 1) * n;  // number of the rest numbers
        while (i > 0) {
            for (int j = 1; j < m; j++) {
                i--;
                pos[0] += dirs[d][0]; pos[1] += dirs[d][1];
                result.push_back(matrix[pos[0]][pos[1]]);
            }
            m--;  // decrease the size of row or column
            swap(m, n);  // switch between horizontal and vertical mode
            d = (d + 1) % 4;  // loop between direction offsets
        }
        return result;
    }
};

int main(int argc, char **argv) {
    int m, n, num;
    cin >> m;
    cin >> n;
    vector<vector<int> > matrix;
    for (int i = 0; i < m; i++) {
        vector<int> line;
        for (int j = 0; j < n; j++) {
            cin >> num;
            line.push_back(num);
        }
        matrix.push_back(line);
    }
    Solution s;
    vector<int> result = s.spiralOrder(matrix);
    cout << "result: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}