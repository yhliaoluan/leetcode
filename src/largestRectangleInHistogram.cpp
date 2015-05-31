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
    vector<int> height;
    for (int i = 1; i < argc; i++) {
        height.push_back(atoi(argv[i]));
    }
    Solution s;
    cout << s.largestRectangleArea(height) << endl;
    return 0;
}
