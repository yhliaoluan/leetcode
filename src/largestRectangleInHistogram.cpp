/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/
#include "header.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        if (height.size() == 1) { return height[0]; }
        vector<vector<int> > f;
        for (int i = 0; i < height.size(); i++) {
            vector<int> line(height.size() - i, 0);
            f.push_back(line);
            f[i][0] = height[i];
            for (int j = i + 1; j < f[i].size(); j++) {
                f[i][j] = min(f[i][j-1], height[j]);
            }
        }
        int largest = 0;
        for (int i = height.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < height.size(); j++) {
                f[i][j] = max(f[i+1][j], max(f[i][j] * (j - i + 1), f[i][j-1]));
                largest = max(largest, f[i][j]);
            }
        }
        return largest;
    }
};

int main(int argc, char **argv) {
    vector<int> height;
    for (int i = 1; i < argc; i++) {
        height.push_back(atoi(argv[i]));
    }
    Solution s;
    cout << s.largestRectangleArea(height) << endl;
    return 0;
}
