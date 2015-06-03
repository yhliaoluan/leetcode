/*
 Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area. 
 * */

#include "header.h"

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int m = matrix[0].size();
        int n = matrix.size();
        vector<int> his(n, 0);
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int index = i;
                while (matrix[j][index] == '1') {
                    index++;
                }
                his[j] = index - i;
            }
            result = max(largestRectangleArea(his), result);
        }
        return result;
    }

    int largestRectangleArea(vector<int>& height) {
        int result = 0;
        height.push_back(0);
        vector<int> index;
        for (int i = 0; i < height.size(); i++) {
            while (!index.empty() && height[index.back()] >= height[i]) {
                int h = height[index.back()];
                index.pop_back();
                int sid = index.empty() ? -1 : index.back();
                result = max(result, h * (i - sid - 1));
            }
            index.push_back(i);
        }
        return result;
    }
};

int main(int argc, char **argv) {
    vector<vector<char> > grid = read_grid<char>();
    Solution s;
    cout << s.maximalRectangle(grid) << endl;
    return 0;
}
