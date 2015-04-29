/*
 *Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 * */
#include "header.h"

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        if (m == 0) { return; }
        int n = matrix[0].size();
        int *array = new int[m + n];
        memset(array, 0, sizeof(int) * (m + n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    array[i] = array[m + j] = 1;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            if (array[i]) {
                for (int j = 0; j < n; j++) { matrix[i][j] = 0; }
            }
        }
        for (int j = m; j < m + n; j++) {
            if (array[j]) {
                for (int i = 0; i < m; i++) { matrix[i][j - m] = 0; }
            }
        }
        delete[] array;
    }
};

int main(int argc, char **argv) {
    vector<vector<int> > matrix = read_grid();
    print_grid(matrix);
    Solution s;
    s.setZeroes(matrix);
    print_grid(matrix);
    return 0;
}
