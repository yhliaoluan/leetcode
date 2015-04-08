/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/
#include "header.h"

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n-i-1; j++) {
                int tmp = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }
    }
};

int main(int argc, char **argv) {
    int n, c;
    cin >> n;
    vector<vector<int> > matrix;
    for (int i = 0; i < n; i++) {
        vector<int> line;
        for (int j = 0; j < n; j++) {
            cin >> c;
            line.push_back(c);
        }
        matrix.push_back(line);
    }
    Solution s;
    s.rotate(matrix);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
